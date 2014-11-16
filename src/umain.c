#include <umain.h>
#include <ustack.h>
#include <ubuffer.h>
#include <umatrix.h>
#include <umesh.h>
#include <ustring.h>
ulib_struct* init_ulib(void)
{
	// Initialize Constructs
	init_stack_construct();
	init_matrix_construct();
	init_buffer_construct();
	init_mesh_construct();
	ulib_struct* new_struct = (ulib_struct*)malloc(sizeof(ulib_struct));
	new_struct->version_major = VER_MAJOR;
	new_struct->version_middle = VER_MIDDLE;
	new_struct->version_minor = VER_MINOR;
	return new_struct;
}

