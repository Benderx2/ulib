#include <ubuffer.h>
buffer_t* CreateBuffer(int sz);
void ResizeBuffer(buffer_t* buffer, int newsize);
void CopyToBuffer(buffer_t* buffer, char* src, int len, int off);
char* GetBufferPointer(buffer_t* buffer);
char GetItemB(buffer_t* buffer, int index);
void SetItemB(buffer_t* buffer, int index, int value);
void init_buffer_construct(void)
{
	Buffer.CreateBuffer = &CreateBuffer;
	Buffer.ResizeBuffer = &ResizeBuffer;
	Buffer.CopyToBuffer = &CopyToBuffer;
	Buffer.GetBufferPointer = &GetBufferPointer;
	Buffer.SetItem = &SetItemB;
	Buffer.GetItem = &GetItemB;
}
buffer_t* CreateBuffer(int sz)
{
	buffer_t* new_buf = (buffer_t*)malloc(sizeof(buffer_t));
	new_buf->len = sz;
	new_buf->content = (char*)malloc(sz * sizeof(char));
	return new_buf;
}
void ResizeBuffer(buffer_t* buffer, int newsize)
{
	// Don't create a new buffer if the assigned size is less, simply set the length variable
	if(newsize < buffer->len) { buffer->len = newsize; }
	else {
		// Pretty Self Explanatory, we reallocate the buffer's storage region
		char* new_buffer = (char*)malloc(newsize);
		int i = 0;
		while(i < buffer->len)
		{
			new_buffer[i] = buffer->content[i];
			i++;
		}
		// Free the previous buffer
		free(buffer->content);
		// Set the pointer and length
		buffer->content = new_buffer;
		buffer->len = newsize;
	}
}
void CopyToBuffer(buffer_t* buffer, char* src, int len, int off)
{
	// We'll check if the source is bigger than our buffer, if yes, the set the length as required
	int final_len = 0;
	// If offset is greater than the length, there's definitely a problem
	if(off >= buffer->len) { return; }
	if(off + len > buffer->len) { final_len = buffer->len - off; } 
	else { final_len = len; } 
	int i = off;
	while(i < final_len)
	{
		buffer->content[i] = src[i-off];
		i++;
	}
}
char* GetBufferPointer(buffer_t* buffer)
{
	return buffer->content;
}
char GetItemB(buffer_t* buffer, int index)
{
	if(index > buffer->len || buffer->content == NULL) { return 0; } 
	else { return (buffer->content[index]); }
}
void SetItemB(buffer_t* buffer, int index, int value)
{
	if(index > buffer->len || buffer->content == NULL) { return; } 
	else { buffer->content[index] = value; }
}
