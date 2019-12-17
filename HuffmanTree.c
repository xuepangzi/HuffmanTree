#include "Tree.h"


//将一个字符串转化为一个以哈夫曼树为结点的数组
void GetFrequency(char *str, HuffmanTree *T, int *n){
	int i = 0;	
	int num[26];
	int len = strlen(str);
	float sum = 0;
	int flag = 1,numPoints = 0;
	
	for (i = 0; i < 26; i++){
		num[i] = 0;
	}
	for (i = 0; i < len; i++){
		switch(str[i]){
			case 'a':num[0]++; break;
			case 'b':num[1]++; break;
			case 'c':num[2]++; break;
			case 'd':num[3]++; break;
			case 'e':num[4]++; break;
			case 'f':num[5]++; break;
			case 'g':num[6]++; break;
			case 'h':num[7]++; break;
			case 'i':num[8]++; break;
			case 'j':num[9]++; break;
			case 'k':num[10]++; break;
			case 'l':num[11]++; break;
			case 'm':num[12]++; break;
			case 'n':num[13]++; break;
			case 'o':num[14]++; break;
			case 'p':num[15]++; break;
			case 'q':num[16]++; break;
			case 'r':num[17]++; break;
			case 's':num[18]++; break;
			case 't':num[19]++; break;
			case 'u':num[20]++; break;
			case 'v':num[21]++; break;
			case 'w':num[22]++; break;
			case 'x':num[23]++; break;
			case 'y':num[24]++; break;
			case 'z':num[25]++; break;
		}
	}

	for (i = 0; i < 26; i++){
		if(num[i] != 0){
			sum+=num[i];
			numPoints++;
		} 
	}
	*n = numPoints;
	if (numPoints != 0){
		*T = (HuffmanTree )malloc(sizeof(HTNode)*(2*numPoints));

		if (T == NULL){
			exit(-1);
		}
		//sum个结点赋予权值与所属值 
		for (i = 1; i <= 26; i++){
			if(num[i-1] != 0){
				(*T)[flag].data = 96 + i;
				(*T)[flag].weight = num[i-1]/sum;
				flag++;
			}
		}
		for (i = 1; i <= 2*numPoints; i++){
			(*T)[i].lchild = 0;
			(*T)[i].rchild = 0;
			(*T)[i].parent = 0;
		}
	}else{
		exit(-1);
	}
}

void Select(HuffmanTree T,int n, int *s1, int *s2){
	int i;
	float max1 = 1, max2 = 1;

	*s1 = *s2 = 1;
	for (i = 1; i <= n; i++){
		if (T[i].weight < max1 && T[i].parent == 0){
			max1 = T[i].weight;
			*s1 = i;
		}else if(T[i].weight < max2 && T[i].parent == 0){
			max2 = T[i].weight;
			*s2 = i;
		}
	}
}

void CreateHuffmanTree(HuffmanTree T, int n){
	int i;
	int s1,s2;
	for (i = n + 1; i <= 2*n-1; i++){
		Select(T, i-1,&s1,&s2);
		T[s1].parent = T[s2].parent = i;
		T[i].lchild = s1;
		T[i].rchild = s2;
		T[i].weight = T[s1].weight+T[s2].weight;
	}
}

char **CreatHuffmanCode(HuffmanTree HT, int n){
	char *cd = (char *)malloc(sizeof(char)*n);
	int i,c,f,start;
	char **hc = (char **)malloc(sizeof(char *)*(n+1));

	cd[n-1] = '\0';
	for(i = 1; i <= n; i++){
		start = n-1;
		c= i;
		f = HT[i].parent;
		while(f != 0){
			--start;
			if(HT[f].lchild == c){
				cd[start] = '0';
			}else{
				cd[start] = '1';
			}
			c = f;
			f = HT[f].parent;
		}
		hc[i] = (char *)malloc(sizeof(char)*(n - start));
		strcpy(hc[i],&cd[start]);
	} 
	free(cd);
	return hc;
}







