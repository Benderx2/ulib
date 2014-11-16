#include <umesh.h>
mesh_t* CreateMesh(string, int);
vec3 GetVector(mesh_t*, int);
void ModifyVector(mesh_t*, int, vec3);
void RenameMesh(mesh_t*, string);
void init_mesh_construct(void)
{
	Mesh.CreateMesh = &CreateMesh;
	Mesh.GetVector = &GetVector;
	Mesh.ModifyVector = &ModifyVector;
	Mesh.RenameMesh = &RenameMesh;
}
mesh_t* CreateMesh(string name, int nvectors)
{
	mesh_t* new_mesh = (mesh_t*)malloc(sizeof(mesh_t));
	new_mesh->name = name;
	new_mesh->vec_count = nvectors;
	new_mesh->vectors = (vec3*)malloc(nvectors*sizeof(vec3));
	return new_mesh;
}
void ModifyVector(mesh_t* mesh, int idx, vec3 vector)
{
	if(idx > mesh->vec_count) { return; }
	else { mesh->vectors[idx] = vector; }
}
vec3 GetVector(mesh_t* mesh, int idx)
{
	if(idx > mesh->vec_count) { }
	else { return mesh->vectors[idx]; }
}
void RenameMesh(mesh_t* mesh, string name)
{
	mesh->name = name;
}
