#include "msViewer2/mathlib.h"
#include "msViewer2/msModel.h"

void updatearraysfromms3dmodel(msModel *ms3dmodel,float *vertexarray,float *normalarray,float vertscale,float normalscale){
	int vertnum=0;
	int numGroups = ms3dmodel->GetNumGroups();
	if(normalarray==NULL){
		for (int i = 0; i < numGroups; i++){
			ms3d_group_t *group = ms3dmodel->GetGroup(i);
			for (size_t j = 0; j < group->triangleIndices.size(); j++){
				ms3d_triangle_t *triangle = ms3dmodel->GetTriangle(group->triangleIndices[j]);
				for (int v = 0; v < 3; v++){
					ms3d_vertex_t *vertex = ms3dmodel->GetVertex(triangle->vertexIndices[v]);
					float positionout[3];
					ms3dmodel->TransformVertex(vertex,positionout);
					vertexarray[vertnum*3+0]=positionout[0]*vertscale;
					vertexarray[vertnum*3+1]=positionout[1]*vertscale;
					vertexarray[vertnum*3+2]=positionout[2]*vertscale;
					vertnum+=1;
				}
			}
		}
	}else{
		for (int i = 0; i < numGroups; i++){
			ms3d_group_t *group = ms3dmodel->GetGroup(i);
			for (size_t j = 0; j < group->triangleIndices.size(); j++){
				ms3d_triangle_t *triangle = ms3dmodel->GetTriangle(group->triangleIndices[j]);
				for (int v = 0; v < 3; v++){
					ms3d_vertex_t *vertex = ms3dmodel->GetVertex(triangle->vertexIndices[v]);
					float positionout[3];
					ms3dmodel->TransformVertex(vertex,positionout);
					vertexarray[vertnum*3+0]=positionout[0]*vertscale;
					vertexarray[vertnum*3+1]=positionout[1]*vertscale;
					vertexarray[vertnum*3+2]=positionout[2]*vertscale;
					float normalout[3];
					ms3dmodel->TransformNormal(vertex,triangle->vertexNormals[v],normalout);
					normalarray[vertnum*3+0]=normalout[0]*normalscale;
					normalarray[vertnum*3+1]=normalout[1]*normalscale;
					normalarray[vertnum*3+2]=normalout[2]*normalscale;
					vertnum+=1;
				}
			}
		}
	}
}

void updatetexturearrayfromms3dmodel(msModel *ms3dmodel,float *texturearray){
	int vertnum=0;
	int numGroups=ms3dmodel->GetNumGroups();
	for(int i=0; i<numGroups; i++){
		ms3d_group_t *group=ms3dmodel->GetGroup(i);
		for(size_t j=0; j<group->triangleIndices.size(); j++){
			ms3d_triangle_t *triangle=ms3dmodel->GetTriangle(group->triangleIndices[j]);
			for(int v=0; v<3; v++){
				texturearray[vertnum*2+0]=triangle->s[v];
				texturearray[vertnum*2+1]=triangle->t[v];
				vertnum+=1;
			}
		}
	}
}

void copyframe(msModel *ms3dmodel,int from,int to){
	for(int a=0;a<ms3dmodel->GetNumJoints();a++){
		//int from=0;
		//for(int b=0;b<ms3dmodel->m_joints[a].rotationKeys.size();b++)
		//	if(ms3dmodel->m_joints[a].rotationKeys[from].time<copyfrom)from=b;*/
		//int to=0;
		//for(int b=0;b<ms3dmodel->m_joints[a].rotationKeys.size();b++)
		//	if(ms3dmodel->m_joints[a].rotationKeys[from].time==copyto)to=b;
		//ms3dmodel->m_joints[a].rotationKeys[0].time=0;
		for(int b=0;b<3;b++){
			ms3dmodel->m_joints[a].rotationKeys[to].key[b]=
				ms3dmodel->m_joints[a].rotationKeys[from].key[b];
			ms3dmodel->m_joints[a].positionKeys[to].key[b]=
				ms3dmodel->m_joints[a].positionKeys[from].key[b];
		}
	}
}
