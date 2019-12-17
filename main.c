#include "Tree.h"

int main(void){
	char str[1000]; 
	int i = 0,j;
	int n;
	char **hc;
	char ch;

	HuffmanTree T;
	printf("请输入字符串\n");
	getchar();
	ch = getchar();
	while(ch != '\n'){
		str[i] = ch;
		i++;
		ch = getchar();
	}
	ch[i] = '\0';
	GetFrequency(str,&T,&n);
	CreateHuffmanTree(T,n);
	printf("\n\n创建哈夫曼结点权值为：\n");
	for (i = 1; i <=n; i++){
		printf("%c：%.2f\n",T[i].data,T[i].weight);
	}
	hc = CreatHuffmanCode(T,n);
	printf("\n哈弗曼编码为：\n");
	for (i = 1; i <= n; i++){
		j = 0;
		printf("%c：",T[i].data);
		while(hc[i][j] != '\0'){
			printf("%c",hc[i][j]);
			j++;
		}
		printf("\n");
	}
}