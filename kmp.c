#include<stdio.h>
#include<malloc.h>
#include<string.h>
int get_length(char *words){
	if(words[0]=='\0')
		return 0;
	else{
		int i=0;
		while(words[i]!='\0')
			i++;
		return i;
	}

}
int get_next(char *s,int *next){
	int length=get_length(s);
	if(length == 0)
		return 0;
	else if(length == 1){
		next[0] == -1;
		return 1;
	}
	else if(length == 2){
		next[0]=-1;
		next[1]=0;
		return 1;
	}
	else{
		next[0]=-1;
                next[1]=0;
		int k=0;
		for(int i=2;i<length;i++){
			k=next[i-1];
			while((s[i-1]!=s[k])&&(k!=-1)){
				k=next[k];
			}
			if(k==-1)
				next[i]==0;
			else{
				next[i]=k+1;
			}
		}
		return 1;
	}
}
int compare(char* src,char* dis,int* next){
	int s_length;
	int dis_length;
	s_length=get_length(src);
	dis_length=get_length(dis);
	int tag=0;
	int i=0,j=0;
	while(i<s_length&&j<dis_length){
		if(src[i]==dis[j]||j==-1){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
		if(j==dis_length-1&&src[i]==dis[j]){
			printf("%c %c",src[i],dis[j]);
			tag=1;
		}
	}
	if(tag==1)
		return 1;
	else
		return 0;
}
int main(){
	char a[10]="abaaba";
	int length=get_length(a);
	int *next =(int *)malloc(sizeof(int)*length);
	if(get_next(a,next)>0){
		printf("生成的next数组如下\n");
		for(int i=0;i<length;i++){
			printf("%d\t",next[i]);
		}
		printf("\n");
	}//if
	char src[30]="abddaabaabbabaabc";
	if(compare(src,a,next)>0)
		printf("给定字符串中包含此字符串\n");
	else{
		printf("很遗憾不包含\n");
	}
	return 0;
}
