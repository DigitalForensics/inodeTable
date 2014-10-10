//
//  main.c
//  inode
//
//  Created by XieZebin on 10/3/14.
//  Copyright (c) 2014 zebin. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

typedef __signed__ char __s8; 
typedef unsigned char __u8; 
typedef __signed__ short __s16; 
typedef unsigned short __u16; 
typedef __signed__ int __s32;
typedef unsigned int __u32; 
typedef __signed__ long long __s64; 
typedef unsigned long long __u64;
typedef __u16 __bitwise __le16;
typedef __u16 __bitwise __be16; 
typedef __u32 __bitwise __le32; 
typedef __u32 __bitwise __be32; 
typedef __u64 __bitwise __le64; 
typedef __u64 __bitwise __be64; 


struct ext2_inode {
    __le16     i_mode;          /* 文件类型和访问权限 */
    __le16     i_uid;          /* 拥有者标识符 */
    __le32     i_size;          /* 以字节为单位的文件长度 */
    __le32     i_atime;     /* 最后一次访问文件的时间 */
    __le32     i_ctime;     /* 索引节点最后改变的时间 */
    __le32     i_mtime;     /* 文件内容最后改变的时间 */
    __le32     i_dtime;     /* 文件删除的时间 */
    __le16     i_gid;          /* 用户组标识符低16位 */      
	__le16     i_links_count;     /* 硬链接计数器 */
    __le32     i_blocks;     /* 文件的数据块数 */
    __le32     i_flags;     /* 文件标志 */
    union {            
			struct {                 
					__le32  l_i_reserved1;           
			} linux1;           
			struct {                 
					__le32  h_i_translator;           
			} hurd1;           
			struct {                 
					__le32  m_i_reserved1;           
			} masix1;       
	} osd1;                    /* 特定的操作系统信息 1 */      
	__le32     i_block[EXT2_N_BLOCKS]; /* 指向数据块的指针 */       
	__le32     i_generation;     /* 文件版本（当网络文件系统访问文件时） */       
	__le32     i_file_acl;     /* 文件访问控制列表 */      
	__le32     i_dir_acl;     /* 目录访问控制列表 */      
	__le32     i_faddr;     /* 片的地址 */      
	union {            
			struct {                 
					__u8     l_i_frag;     /* Fragment number */   
	   				__u8     l_i_fsize;     /* Fragment size */   
	   				__u16     i_pad1;     
					__le16     l_i_uid_high;     /* these 2 fields    */  
	  				__le16     l_i_gid_high;     /* were reserved2[0] */  
	  				__u32     l_i_reserved2; 
  			} linux2;  
   			struct {      
		 			__u8     h_i_frag;     /* Fragment number */
					__u8     h_i_fsize;     /* Fragment size */
					__le16     h_i_mode_high;      
		  			__le16     h_i_uid_high; 
	 				__le16     h_i_gid_high; 
	 				__le32     h_i_author;
 			} hurd2;
 			struct { 
					__u8     m_i_frag;     /* Fragment number */ 
	 				__u8     m_i_fsize;     /* Fragment size */ 
	 				__u16     m_pad1;
					__u32     m_i_reserved2[2]; 
  			} masix2; 
	} osd2;                    /* 特定的操作系统信息 2 */

};
