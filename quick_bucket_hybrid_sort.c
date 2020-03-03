// ILBEY EVCİL - 2079242

#include <stdio.h>
#include <stdlib.h>

double *A;
int *B;
int n;

void printArray();
int bucketSort();
void quickSort(int,int);
int partition(int,int);

int main()
{
	
        int i,error;
        scanf("%d",&n);
        
        A = (double *)malloc(sizeof(double)*n);
	B = (int *)malloc(sizeof(int)*n);


              

        for (i=0;i<n;i++)
                scanf("%lf",A+i);

        printArray();
        printf("\n");
        error=bucketSort();
	
	if(error<=0){	
		printArray();}
	else{
		quickSort(0,n-1);
		printArray();}
	
}


void printArray()
{
        int i;


        for (i=0;i<n;i++)
	{     
                printf("%.12lf",A[i]);
                printf("\n");       
	}	
}




int bucketSort()
{        
        int i, j=0, a=0, check=0, error=0; 
	double temp;
	double count[n][4];
    
	
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			count[i][j]=-1;
		}
	}       
        

        
        for(i=0;i<n;i++)
            B[i]=A[i]*n;


        i=0;

for(a=0;a<n;a++){ 
	j=0;
	check=0;   
	i=B[a];  
	while(check<=0){      
        	if(count[i][j]==-1){
        		count[i][j]=A[a];
			check++;
		}
		else{
			j++;
			if(j>=3){
				error++;
			}
		}
	}

}
       
j=0;

if(error<=0){ 
	for(i=0;i<n;i++){
			for(j=0;j<4;j++){
				if(count[i][j]!=-1){
				}
			}
		}       




	    for(a=0;a<n;a++)
	    {
		for(i=0;i<3;i++)
		{
			temp=count[a][i];
			j=i-1; 
			while(j>=0 && count[a][j]>=temp)
			{
				count[a][j+1]=count[a][j];
				j=j-1;
			}
			count[a][j+1]=temp;
		}
	
	    }

}


a=0;
while(a<n){
	for(i=0;i<n;i++){
			for(j=0;j<4;j++){
				if(count[i][j]!=-1){
				A[a]=count[i][j];
				a++;
				}
			}
		} 
}


return error;
}




void quickSort(int p, int r)
{
	int q;
	
	printf("QQQQQQQ\n");
	if (p>=r) return;

	q = partition(p,r);

	quickSort(q+1,r);
	quickSort(p,q-1);
}




int partition(int p, int r)
{
	double x, tmp;
	int i,j;
	int randind;
	/*x = A[r];*/
	randind = p+rand()%(r-p+1);

	x = A[randind];

	/*put the pivot to the end */
	tmp = A[r];
	A[r] = A[randind];
	A[randind] = tmp;

	i = p-1;

	for (j=p;j<r;j++)
	{
		if (A[j]<=x)
		{
			i++;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}

	tmp = A[i+1];
	A[i+1] = A[r];
	A[r] = tmp;

	return i+1;
} 






