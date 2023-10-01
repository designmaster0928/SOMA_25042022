/*
 * files.h
 *
 *  Created on: May 19, 2022
 *      Author: Administrator
 */

#ifndef INC_FILES_H_
#define INC_FILES_H_


#ifdef __cplusplus
extern "C" {
#endif


#include "main.h"


FILE  *ob_fopen(const char *filename, const char *mode);
int    ob_fclose(FILE *stream);
size_t ob_fread(void *ptr, size_t size, size_t count, FILE *stream);
size_t ob_fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
int    ob_fflush(FILE *stream);
int    ob_feof(FILE *stream);
int    ob_fseek(FILE *stream, long offset, int whence);
long   ob_ftell(FILE *stream);
int    ob_fgetc(FILE *stream);
char*  ob_fgets(char* str, int num, FILE* stream);


#define fopen     ob_fopen
#define fclose    ob_fclose
#define fread     ob_fread
#define fwrite    ob_fwrite
#define fgets     ob_fgets
#define fseek     ob_fseek
#define rewind    ob_frewind
#define fgetc     ob_fgetc
#define ftell     ob_ftell


#ifdef __cplusplus
}
#endif


#endif /* INC_FILES_H_ */
