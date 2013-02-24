#include "glhProjectf.h"
float cammodelviewmatrix[16];
float camprojectionmatrix[16];
float savedcammodelviewmatrix[16];
float savedcamprojectionmatrix[16];

void set2dcamera(float top,float bottom,float left,float right){
	//disable depth test
	glDisable(GL_DEPTH_TEST);
	//setup the camera
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//apply the top, bottom, left and right settings
	gluOrtho2D(left,right,bottom,top);
}

void draw2dquad(float posx,float posy,float sizex,float sizey,float *texturecoords,int centerandrotate,float angle){
	if(centerandrotate==0){
		float verts[]={
			posx,		posy+sizey,
			posx+sizex,	posy+sizey,
			posx+sizex,	posy,
			posx,		posy,};
		glVertexPointer(2,GL_FLOAT,0,verts);
		glTexCoordPointer(2,GL_FLOAT,0,texturecoords);
		glDrawArrays(GL_QUADS,0,4);
	}else if(angle==0){
		sizex*=0.5f;
		sizey*=0.5f;
		float verts[]={
			posx-sizex,	posy+sizey,
			posx+sizex,	posy+sizey,
			posx+sizex,	posy-sizey,
			posx-sizex,	posy-sizey,};
		glVertexPointer(2,GL_FLOAT,0,verts);
		glTexCoordPointer(2,GL_FLOAT,0,texturecoords);
		glDrawArrays(GL_QUADS,0,4);
	}else{
		sizex*=0.5f;
		sizey*=0.5f;
		float verts[]={
			0-sizex,	0+sizey,
			0+sizex,	0+sizey,
			0+sizex,	0-sizey,
			0-sizex,	0-sizey,};
		glPushMatrix();
		glTranslatef(posx,posy,0);
		glRotatef(angle*degreesinradian,0,0,1);
		glVertexPointer(2,GL_FLOAT,0,verts);
		glTexCoordPointer(2,GL_FLOAT,0,texturecoords);
		glDrawArrays(GL_QUADS,0,4);
		glPopMatrix();
	}
}

void savecammatrix(){
	for(int a=0;a<16;a++)savedcammodelviewmatrix[a]=cammodelviewmatrix[a];
	for(int a=0;a<16;a++)savedcamprojectionmatrix[a]=camprojectionmatrix[a];
}

void loadcammatrix(){
	for(int a=0;a<16;a++)cammodelviewmatrix[a]=savedcammodelviewmatrix[a];
	for(int a=0;a<16;a++)camprojectionmatrix[a]=savedcamprojectionmatrix[a];
}

void multiplymatrixtocammatrix(float newmatrix[16]){
	//http://fhtr.blogspot.com/2010/02/4x4-float-matrix-multiplication-using.html
	float tempmatrix[16]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,};
	for(int a=0;a<16;a++)tempmatrix[a]=cammodelviewmatrix[a];
	float *a=&tempmatrix[0];
	float *b=&newmatrix[0];
	float *c=&cammodelviewmatrix[0];
	for(int i=0; i<16; i+=4)for(int j=0; j<4; j++)
		c[i+j] = b[i]*a[j] + b[i+1]*a[j+4] + b[i+2]*a[j+8] + b[i+3]*a[j+12];
}

void translatecam(float x,float y,float z){
	float result[16]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,};
	result[3*4+0] = x;
	result[3*4+1] = y;
	result[3*4+2] = z;
	multiplymatrixtocammatrix(result);
}

void rotatecam(float angle,float x,float y,float z){
	float fcos = cos(angle*radiansindegree), fsin = sin(angle*radiansindegree);
	float result[16]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,};
	if(x==1){
		result[1*4+1]=fcos;
		result[2*4+1]=-fsin;
		result[1*4+2]=fsin;
		result[2*4+2]=fcos;
	}else if(y==1){
		result[0*4+0]=fcos;
		result[2*4+0]=fsin;
		result[0*4+2]=-fsin;
		result[2*4+2]=fcos;
	}else if(z==1){
		result[0*4+0]=fcos;
		result[1*4+0]=-fsin;
		result[0*4+1]=fsin;
		result[1*4+1]=fcos;
	}
	multiplymatrixtocammatrix(result);
}

void scalecam(float x,float y,float z){
	float result[16]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,};
    result[0*4+0]=x;
    result[1*4+1]=y;
    result[2*4+2]=z;
	multiplymatrixtocammatrix(result);
}

void set3dcamera(float posx,float posy,float posz,float xang,float yang,float zang,float fov,float aspect,float nearrange,float farrange){
	//setup the camera
	set2dcamera(1,0,0,1);
	//enable depth test
	glEnable(GL_DEPTH_TEST);
	//diy matrix
	float tempmatrix1[16]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,};
	for(int a=0;a<16;a++)cammodelviewmatrix[a]=tempmatrix1[a];
	float f=tan(PI*0.5f-(fov*0.5f*radiansindegree));
	float tempmatrix2[16]={
		f/aspect,	0,	0,												0,
		0,			f,	0,												0,
		0,			0,	(farrange+nearrange)/(nearrange-farrange),		-1,
		0,			0,	(2*farrange*nearrange)/(nearrange-farrange),	0,
	};
	for(int a=0;a<16;a++)camprojectionmatrix[a]=tempmatrix2[a];
	//rotate
	rotatecam(xang*degreesinradian,1,0,0);
	rotatecam(yang*degreesinradian,0,1,0);
	rotatecam(zang*degreesinradian,0,0,1);
	//position
	translatecam(-posx,-posy,-posz);
}

bool polygonvisible(float x1,float y1,float x2,float y2,float x3,float y3){
	//http://cgafaq.info/wiki/2D_Polygon_Backface_Culling
	if((x1-x2)*(y3-y2)-(y1-y2)*(x3-x2)<0.f){return 1;}else{return 0;}
}

void draw3dtrianglemesh(int vertexcount,float *verts,float *texturecoords,float *colors,float *normals){
	int viewport[] = {0,0,1,1};
	/*float winpos[3*3];
	for(int a=0; a<vertexcount; a+=3){
		glhProjectf(verts[a*3+0],verts[a*3+1],verts[a*3+2],&cammodelviewmatrix[0],&camprojectionmatrix[0],viewport,&winpos[0]);
		glhProjectf(verts[a*3+3],verts[a*3+4],verts[a*3+5],&cammodelviewmatrix[0],&camprojectionmatrix[0],viewport,&winpos[3]);
		glhProjectf(verts[a*3+6],verts[a*3+7],verts[a*3+8],&cammodelviewmatrix[0],&camprojectionmatrix[0],viewport,&winpos[6]);
		if(winpos[2]<1.f && winpos[5]<1.f && winpos[8]<1.f
		&& winpos[2]>0.f && winpos[5]>0.f && winpos[8]>0.f
		&& polygonvisible(winpos[0],winpos[1],winpos[3],winpos[4],winpos[6],winpos[7])){
			float verts[]={
				winpos[0],winpos[1],-winpos[2],
				winpos[3],winpos[4],-winpos[5],
				winpos[6],winpos[7],-winpos[8],
			};
			glVertexPointer(3,GL_FLOAT,0,verts);
			glTexCoordPointer(2,GL_FLOAT,0,&texturecoords[a*2]);
			if(colors!=NULL)glColorPointer(3,GL_FLOAT,0,&colors[a*3]);
			glDrawArrays(GL_TRIANGLES,0,3);
		}
	}*/
	float winpos[3*3];
	for(int a=0; a<vertexcount; a+=3){
		glhProjectf(verts[a*3+0],verts[a*3+1],verts[a*3+2],&cammodelviewmatrix[0],&camprojectionmatrix[0],viewport,&winpos[0]);
		glhProjectf(verts[a*3+3],verts[a*3+4],verts[a*3+5],&cammodelviewmatrix[0],&camprojectionmatrix[0],viewport,&winpos[3]);
		glhProjectf(verts[a*3+6],verts[a*3+7],verts[a*3+8],&cammodelviewmatrix[0],&camprojectionmatrix[0],viewport,&winpos[6]);
		if(winpos[2]>0.f && winpos[5]>0.f && winpos[8]>0.f){
			float verts[]={
				winpos[0],winpos[1],-winpos[2],
				winpos[3],winpos[4],-winpos[5],
				winpos[6],winpos[7],-winpos[8],
			};
			for(int v=0;v<3;v++)if(winpos[v*3+2]>1.f){
				//verts[v*3+0]*=-1.f;
				//verts[v*3+1]*=-1.f;
				verts[v*3+0]=(verts[v*3+0]-0.5f)*(-PI)+0.5f;
				verts[v*3+1]=(verts[v*3+1]-0.5f)*(-PI)+0.5f;
				//winpos[v*3+2]=0.95f;
			}
			for(int v=0;v<3;v++)winpos[v*3+2]=0.5f;
			if(polygonvisible(verts[0],verts[1],verts[3],verts[4],verts[6],verts[7])){
				glVertexPointer(3,GL_FLOAT,0,verts);
				glTexCoordPointer(2,GL_FLOAT,0,&texturecoords[a*2]);
				glDrawArrays(GL_TRIANGLES,0,3);
			}
		}
	}
}

void draw3dquadmesh(int vertexcount,float *verts,float *texturecoords,float *colors,float *normals){
	int viewport[] = {0,0,1,1};
	float winpos[3*4];
	for(int a=0; a<vertexcount; a+=4){
		glhProjectf(verts[a*3+0],verts[a*3+1],verts[a*3+2],&cammodelviewmatrix[0],&camprojectionmatrix[0],viewport,&winpos[0]);
		glhProjectf(verts[a*3+3],verts[a*3+4],verts[a*3+5],&cammodelviewmatrix[0],&camprojectionmatrix[0],viewport,&winpos[3]);
		glhProjectf(verts[a*3+6],verts[a*3+7],verts[a*3+8],&cammodelviewmatrix[0],&camprojectionmatrix[0],viewport,&winpos[6]);
		glhProjectf(verts[a*3+9],verts[a*3+10],verts[a*3+11],&cammodelviewmatrix[0],&camprojectionmatrix[0],viewport,&winpos[9]);
		if(winpos[2]<1.f && winpos[5]<1.f && winpos[8]<1.f && winpos[11]<1.f
		&& winpos[2]>0.f && winpos[5]>0.f && winpos[8]>0.f && winpos[11]>0.f){
			float verts[]={
				winpos[0],winpos[1],-winpos[2],
				winpos[3],winpos[4],-winpos[5],
				winpos[6],winpos[7],-winpos[8],
				winpos[9],winpos[10],-winpos[11],
			};
			glVertexPointer(3,GL_FLOAT,0,verts);
			glTexCoordPointer(2,GL_FLOAT,0,&texturecoords[a*2]);
			if(colors!=NULL)glColorPointer(3,GL_FLOAT,0,&colors[a*3]);
			glDrawArrays(GL_QUADS,0,4);
		}
	}
}
