/*
Ali Ozturk - 150114061
*/

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "BSTKutuphane.c"
#include "AVLKutuphane.c"


int main(){
	
	 system("color A");
	 
	 /* BST Tree */
	 printf("\n__________________________________BST__________________________________________ \n\n");
	
	dugumBST *kokAgacBST=NULL;	 	 
	  

//execution time for BST insertion >>>
printf("              <<<<<<execution time for insertion>>>>>>>       \n\n");
double timeBST_1;
     
     int j;
     for(j=1;j<10;j++){
	
     clock_t beginBST_1 = clock();
     int i;
	 for(i=0;i<1000*j;i++){
	 	kokAgacBST= dosyaOkuBST(kokAgacBST,"file1.txt");
	 }
	  clock_t endBST_1 = clock();
			timeBST_1 =  (double)(endBST_1 - beginBST_1)*100 / CLOCKS_PER_SEC;
			beginBST_1=0;
		    endBST_1 =0;
	 printf("Insertion time on %d : %fl\n",i,timeBST_1);	 
	  }
	  	 

//execution time for BST deletion	>>>
printf("\n              <<<<<<execution time for deletion>>>>>>>       \n\n");	 
	double timeBST_2=0; 
	 
for(j=1;j<10;j++){
	
 
 int i3;
	for(i3=0;i3<1000*j;i3++){
		
	kokAgacBST= dosyaOkuBST(kokAgacBST,"file1.txt");
		  clock_t beginBST2 = clock();
	 	  ilkCumleyiSilBST(kokAgacBST);
	 	  clock_t endBST2 = clock();
	 	 timeBST_2 = timeBST_2+ (double)(endBST2 - beginBST2)*100 / CLOCKS_PER_SEC;
	 	 beginBST2=0;
		    endBST2 =0;
	 }
	  
			
			
	 printf("Deletion time on %d : %fl\n",i3,timeBST_2);	 
	 
}	 
	printf("\n                  <<<<<<Memory space for BST>>>>>>>       \n");	
	 
	// memeroy space for BST
	 memoryUsage_BST(kokAgacBST);
	 


     printf("_______________________________________________________________________________ \n");
        
     
     printf("\n__________________________________AVL__________________________________________ \n");
     
	 dugumAVL *kokAgacAVL = NULL;     

     
              
//execution time for AVL insertion >>>
printf("\n              <<<<<<execution time for insertion>>>>>>>       \n\n");	
     double timeAVL;
     
    
     for(j=1;j<10;j++){
	
     clock_t begin = clock();
     int i;
	 for(i=0;i<1000*j;i++){
	 	kokAgacAVL = dosyaOkuAVL(kokAgacAVL,"file2.txt");
	 }
	  clock_t end = clock();
			timeAVL =  (double)(end - begin)*100 / CLOCKS_PER_SEC;
			begin=0;
		    end =0;
	 printf("Insertion time on %d : %fl\n",i,timeAVL);	 
	  }




//execution time for BST deletion	>>>
printf("\n              <<<<<<execution time for deletion>>>>>>>       \n\n");	
 timeAVL=0;
 for(j=1;j<10;j++){
	

 int i2;
	for(i2=0;i2<1000*j;i2++){
			
		 kokAgacAVL = dosyaOkuAVL(kokAgacAVL,"file2.txt");
		  clock_t begin2 = clock();
	 	 ilkCumleyiSilAVL(kokAgacAVL);
	 	 clock_t end2 = clock();
			timeAVL = timeAVL+ (double)(end2 - begin2)*100 / CLOCKS_PER_SEC;
			begin2=0;
		    end2 =0;
	 	 
	 }
	  
	 printf("Deletion time on %d: %fl\n",i2,timeAVL);	 
	 
}	 
	printf("\n                  <<<<<<Memory space for BST>>>>>>>       \n");	
	 
	 memoryUsage_AVL(kokAgacAVL);
	 
     
     
     printf("________________________________________________________________________________ \n");
    return 0;
}












