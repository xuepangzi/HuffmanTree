#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char data;
	float weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;

void GetFrequency(char *str, HuffmanTree *T, int *n);
void Select(HuffmanTree T,int n, int *s1, int *s2);
void CreateHuffmanTree(HuffmanTree T, int n);
char **CreatHuffmanCode(HuffmanTree HT,int n);
#endif