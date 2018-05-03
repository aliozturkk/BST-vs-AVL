/*
Ali Ozturk - 150114061
*/

#ifndef aliOzturkKutuphane
#define aliOzturkKutuphane
typedef struct dugumAVL {
	
	char veri[42];
	struct dugumAVL *solKol;
	struct dugumAVL *sagKol;
    unsigned int height;
   
}dugumAVL;

// for avl  

dugumAVL *dosyaOkuAVL(dugumAVL *kokAgac,char dosyaIsmi[42]);
void sayiciAVL(dugumAVL *liste);
int max(int a, int b);
int height(dugumAVL *N);
dugumAVL * minValueNode(dugumAVL *node);
dugumAVL* newNode(char veri[42]);
dugumAVL *rightRotate(dugumAVL *y);
dugumAVL *leftRotate(dugumAVL *x);
int getBalance(dugumAVL *N);
dugumAVL* insert(dugumAVL* node, char veri[42]);
dugumAVL* deleteNode(dugumAVL* kokAVL, char veri[42]);
void ilkCumleyiSilAVL(dugumAVL *kokAgac);
double AVLInsertionTime(char fileName[42],int sefer);
double AVLDeletionTime(char fileName[42],int sefer);
void memoryUsageAVL(dugumAVL *dugum);

#endif
