/*
Ali Ozturk - 150114061
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "AVLKutuphane.h"
int toplamDugumAVL=0;
//____________________________________________AVL Library_________________________________________________\\





//print tree
void sayiciAVL(dugumAVL *liste) 
{
			
	if (liste!=NULL)
	{
				
		sayiciAVL(liste->solKol);		
		sayiciAVL(liste->sagKol);
	    toplamDugumAVL++;  
	}

	
}



//---------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------This below part by copy from www.geeksforgeeks.org  --------------------------------------

dugumAVL *dosyaOkuAVL(dugumAVL *kokAgac,char dosyaIsmi[42])
{
	

    FILE *dosya;
	dosya=fopen(dosyaIsmi,"r");    
    char veriKutusu[1071];
    int sayac=0;
    
		while(fscanf(dosya,"%s",veriKutusu)!=EOF)
		{    		
	 		// exist other dugum
		    kokAgac=insert(kokAgac,veriKutusu);	
																	      
		}
		fclose(dosya);
	return kokAgac;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------This below part by copy from www... ------------------------------------------------ 
// A utility function to get height of the tree
int height(dugumAVL *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
dugumAVL* newNode(char veri[1071])
{
    dugumAVL* node = (struct dugumAVL*)malloc(sizeof(struct dugumAVL));                      
    strcpy(node->veri, veri);
    node->solKol   = NULL;
    node->sagKol  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
dugumAVL *rightRotate(dugumAVL *y)
{
    dugumAVL *x = y->solKol;
    dugumAVL *T2 = x->sagKol;
 
    // Perform rotation
    x->sagKol = y;
    y->solKol = T2;
 
    // Update heights
    y->height = max(height(y->solKol), height(y->sagKol))+1;
    x->height = max(height(x->solKol), height(x->sagKol))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
dugumAVL *leftRotate(dugumAVL *x)
{
   dugumAVL *y = x->sagKol;
   dugumAVL *T2 = y->solKol;
 
    // Perform rotation
    y->solKol = x;
    x->sagKol = T2;
 
    //  Update heights
    x->height = max(height(x->solKol), height(x->sagKol))+1;
    y->height = max(height(y->solKol), height(y->sagKol))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(dugumAVL *N)
{
    if (N == NULL)
        return 0;
    return height(N->solKol) - height(N->sagKol);
}
 
// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
dugumAVL* insert(dugumAVL* node, char veri[1071])
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(veri));
 
    if (strcmp(veri , node->veri)<0)
        node->solKol  = insert(node->solKol, veri);
    else if (strcmp(veri , node->veri)>0)
        node->sagKol = insert(node->sagKol, veri);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->solKol),
                           height(node->sagKol));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && strcmp(veri ,node->solKol->veri)<0)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && strcmp(veri ,node->sagKol->veri)>0)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && strcmp(veri ,node->solKol->veri)>0)
    {
        node->solKol =  leftRotate(node->solKol);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && strcmp(veri ,node->sagKol->veri)<0) 
    {
        node->sagKol = rightRotate(node->sagKol);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 
// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(dugumAVL *root)
{
    if(root != NULL)
    {
        printf("%s \n", root->veri);
        preOrder(root->solKol);
        preOrder(root->sagKol);
    }
}
 
      /*--------------deletion -------------*/
dugumAVL* deleteNode(dugumAVL *kokAVL, char veri[42])
{
    // STEP 1: PERFORM STANDARD BST DELETE
 
    if (kokAVL == NULL)
        return kokAVL;
 
    // If the key to be deleted is smaller than the
    // kokAVL's key, then it lies in left subtree
    if ( strcmp(veri , kokAVL->veri)<0 )
        kokAVL->solKol = deleteNode(kokAVL->solKol, veri);
 
    // If the key to be deleted is greater than the
    // kokAVL's key, then it lies in right subtree
    else if( strcmp(veri , kokAVL->veri)>0 )
        kokAVL->sagKol = deleteNode(kokAVL->sagKol, veri);
 
    // if key is same as kokAVL's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (kokAVL->solKol == NULL) || (kokAVL->sagKol == NULL) )
        {
            dugumAVL *temp = kokAVL->solKol ? kokAVL->solKol :
                                             kokAVL->sagKol;
 
            // No child case
            if (temp == NULL)
            {
                temp = kokAVL;
                kokAVL = NULL;
            }
            else // One child case
             *kokAVL = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            dugumAVL* temp = minValueNode(kokAVL->sagKol);
 
            // Copy the inorder successor's data to this node
            strcpy(kokAVL->veri, temp->veri);
 
            // Delete the inorder successor
            kokAVL->sagKol = deleteNode(kokAVL->sagKol, temp->veri);
        }
    }
 
    // If the tree had only one node then return
    if (kokAVL == NULL)
      return kokAVL;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    kokAVL->height = 1 + max(height(kokAVL->solKol),
                           height(kokAVL->sagKol));
 
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(kokAVL);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(kokAVL->solKol) >= 0)
        return rightRotate(kokAVL);
 
    // Left Right Case
    if (balance > 1 && getBalance(kokAVL->solKol) < 0)
    {
        kokAVL->solKol =  leftRotate(kokAVL->solKol);
        return rightRotate(kokAVL);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(kokAVL->sagKol) <= 0)
        return leftRotate(kokAVL);
 
    // Right Left Case
    if (balance < -1 && getBalance(kokAVL->sagKol) > 0)
    {
        kokAVL->sagKol = rightRotate(kokAVL->sagKol);
        return leftRotate(kokAVL);
    }
 
    return kokAVL;
}
dugumAVL *minValueNode (dugumAVL *agac)
{
// returns a pointer to node with the minimum key in the BST.
// which one is the node with the minimum key in a BST?
		if (agac != NULL){
		while (agac->solKol != NULL)
		agac=agac->solKol;	
		}
		
		
		return agac;

}
void ilkCumleyiSilAVL(dugumAVL *kokAgac)
{
	
	FILE *dosya;
	dosya=fopen("file2.txt","r");    
    char veriKutusu[42];
    int sayac=0;
    int i;
    while(fscanf(dosya,"%s",veriKutusu)!=EOF)
	{    
	      
		kokAgac=deleteNode(kokAgac,veriKutusu);
		
	          for(i=0;veriKutusu[i]!=0;i++){  
	          	  
					if(veriKutusu[i]<=47 && veriKutusu[i]>=33){
	          	  	
	          	  	 sayac=1;
	          	  	 
					}
			  }	
			
				if(sayac==1){
					break;
				}				  						      
	} 
	fclose(dosya);
}
 
 
 
// -------------------------EXECUTÝON TÝME -------------------

// FOR ÝNSERTÝON >>

double AVLInsertionTime(char fileName[42],int sefer)
{	
        dugumAVL * kokAgacAVL;	  
		clock_t begin = clock();
		int i;	
		
		for(i = 0; i < sefer; i++)
		{
		
		   kokAgacAVL=NULL;
			kokAgacAVL= dosyaOkuAVL(kokAgacAVL,fileName);
			  
		}
		clock_t end = clock();
		double time = (double)(end - begin)*100 / CLOCKS_PER_SEC;
		return time;
	
}



//FOR MEMORY USaGE

void memoryUsage_AVL(dugumAVL *dugum)
{
     	

	sayiciAVL(dugum); 
	int numberOfMallocs_AVL = 0;
	int i;
	for( i = 0; i < toplamDugumAVL; i++)
	{
		numberOfMallocs_AVL += sizeof(dugum->veri);
		
		numberOfMallocs_AVL += sizeof(dugum->solKol);
		numberOfMallocs_AVL += sizeof(dugum->sagKol);
		numberOfMallocs_AVL += sizeof(dugum->height);
	}

	 printf("\nMemory Space : %d\n",numberOfMallocs_AVL);
}






