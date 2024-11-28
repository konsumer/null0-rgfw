#pragma once

// this defines interaction with cart for native

// MEMORY

// copy a pointer from cart to host
void* cart_get_pointer(unsigned int cartPtr, unsigned int len);

// copy a pointer from host to cart
unsigned int cart_set_pointer(void* hostPtr, unsigned int len, unsigned int cartPtr);

// copy a string from cart to host
char* cart_get_string(unsigned int cartPtr);

// copy a string from host to cart
unsigned int cart_set_string(char* hostPtr);

// allocate cart-memory from host C
unsigned int cart_malloc(int size);

// free cart-memory from host C
void cart_free (unsigned int ptr);

// LIFECYCLE

// called on cart init
void null0_host_load(unsigned char* wasmBytesPtr, int wasmBytesLen);

// called on cart update
void null0_host_update(double timeMs);

// called on cart unload
void null0_host_unload();