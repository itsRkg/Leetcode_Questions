
bool find(int *candidates, int candidatesSize,int **arr, int *returnSize, int** returnColumnSizes,int depth,int target,int curr_index)
{   if(target<0) return false;
    
    if(target==0) 
    {
        arr[*returnSize]=malloc(sizeof(int)*(depth));
        (*returnColumnSizes)[(*returnSize)++]=depth;
        return true;
    }
int index=*returnSize,i,flag=0;

for(i=curr_index;i<candidatesSize;i++)
{
    if(i && candidates[i]==candidates[i-1] && i>curr_index)
        continue;
    if(find(candidates, candidatesSize,arr, returnSize, returnColumnSizes,depth+1,target-candidates[i],i+1))
    {
        while(index<(*returnSize))
            arr[index++][depth]=candidates[i];     
        flag=1;
       
    }
}
 if(flag==1) return true;
   
 else   
     return false;
}

int comparator(const void *p, const void *q) 
{
    return ( *(int*)p - *(int*)q );
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
int **arr;
int i;
qsort(candidates,candidatesSize,sizeof(candidates[0]),comparator);
arr=malloc(sizeof(int*)*150);
(*returnColumnSizes)=malloc(sizeof(int)*150);
*returnSize=0;
bool done = find(candidates, candidatesSize,arr, returnSize, returnColumnSizes,0,target,0);
return arr;
}
