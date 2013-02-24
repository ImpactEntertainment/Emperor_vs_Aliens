#ifndef PS3
//calculate the normal from a triangle polygon
void calculatetrianglenormal(
	float vx0, float vy0, float vz0,
	float vx1, float vy1, float vz1,
	float vx2, float vy2, float vz2,
	float &nx, float &ny, float &nz){
		//subtract vectors
		float ax=vx1-vx0;
		float ay=vy1-vy0;
		float az=vz1-vz0;
		float bx=vx2-vx1;
		float by=vy2-vy1;
		float bz=vz2-vz1;
		//calculate face normal using cross product
		nx=ay*bz-az*by;
		ny=az*bx-ax*bz;
		nz=ax*by-ay*bx;
		//normalize it 
		float l=sqrt(nx*nx+ny*ny+nz*nz);
		nx=-nx/l;
		ny=-ny/l;
		nz=-nz/l;
}

void updatetrianglenormalarray(int vertexcount,float *vertexarray,float *normalarray){
	for(int a=0;a<vertexcount;a+=3){
		float nx=0.f,ny=0.f,nz=0.f;
		calculatetrianglenormal(
			vertexarray[(a+0)*3+0],
			vertexarray[(a+0)*3+1],
			vertexarray[(a+0)*3+2],
			vertexarray[(a+1)*3+0],
			vertexarray[(a+1)*3+1],
			vertexarray[(a+1)*3+2],
			vertexarray[(a+2)*3+0],
			vertexarray[(a+2)*3+1],
			vertexarray[(a+2)*3+2],
			nx,ny,nz);
		normalarray[(a+0)*3+0]=-nx;
		normalarray[(a+0)*3+1]=-ny;
		normalarray[(a+0)*3+2]=-nz;
		normalarray[(a+1)*3+0]=-nx;
		normalarray[(a+1)*3+1]=-ny;
		normalarray[(a+1)*3+2]=-nz;
		normalarray[(a+2)*3+0]=-nx;
		normalarray[(a+2)*3+1]=-ny;
		normalarray[(a+2)*3+2]=-nz;
	}
}

void updatequadnormalarray(int vertexcount,float *vertexarray,float *normalarray){
	for(int a=0;a<vertexcount;a+=4){
		float nx=0.f,ny=0.f,nz=0.f;
		calculatetrianglenormal(
			vertexarray[(a+0)*3+0],
			vertexarray[(a+0)*3+1],
			vertexarray[(a+0)*3+2],
			vertexarray[(a+1)*3+0],
			vertexarray[(a+1)*3+1],
			vertexarray[(a+1)*3+2],
			vertexarray[(a+2)*3+0],
			vertexarray[(a+2)*3+1],
			vertexarray[(a+2)*3+2],
			nx,ny,nz);
		normalarray[(a+0)*3+0]=-nx;
		normalarray[(a+0)*3+1]=-ny;
		normalarray[(a+0)*3+2]=-nz;
		normalarray[(a+1)*3+0]=-nx;
		normalarray[(a+1)*3+1]=-ny;
		normalarray[(a+1)*3+2]=-nz;
		normalarray[(a+2)*3+0]=-nx;
		normalarray[(a+2)*3+1]=-ny;
		normalarray[(a+2)*3+2]=-nz;
		normalarray[(a+3)*3+0]=-nx;
		normalarray[(a+3)*3+1]=-ny;
		normalarray[(a+3)*3+2]=-nz;
	}
}
#endif
