/* hash_print.h - functions to print message digests */
#ifndef HASH_PRINT_H
#define HASH_PRINT_H

#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Name and other info of a hash function
 */
typedef struct print_hash_info
{
	const char* name;
	const char* bsd_name;
	unsigned hash_id;
	char short_name[20];
	char short_char;
} print_hash_info;

extern print_hash_info hash_info_table[];

struct file_info;
struct file_t;
struct print_item;
struct strbuf_t;

/* initialization of static data */
void init_hash_info_table(void);
struct strbuf_t* init_printf_format(void);

/* formatted output of message digests and file information */
struct print_item* parse_print_string(const char* format, uint64_t* hash_mask);
int print_line(FILE* out, unsigned out_mode, struct print_item* list, struct file_info* info);
void free_print_list(struct print_item* list);

/* SFV format functions */
int print_sfv_banner(FILE* out);
int print_sfv_header_line(FILE* out, unsigned out_mode, struct file_t* file);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* HASH_PRINT_H */
