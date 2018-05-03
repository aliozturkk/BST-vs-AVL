/*
Ali Ozturk - 150114061
*/

#ifndef BSTKutuphane
#define BSTKutuphane
typedef struct dugumBST {
	
	char veri[40];
	struct dugumBST *solKol;
	struct dugumBST *sagKol;

   
}dugumBST;

dugumBST *dosyaOkuBST(dugumBST *kokAgac,char dosyaIsmi[42]);
dugumBST *dugumEkle(dugumBST *kokAgac,char veriKutusu[42]);
void sayiciBST(dugumBST *liste);
dugumBST *bulMin (dugumBST *agac);
void ilkCumleyiSilBST(dugumBST *kokAgac);
double BSTInsertionTime(char fileName[42],int sefer);
double BSTDeletionTime(char fileName[42],int sefer);
void memoryUsage_BST(dugumBST *dugum);

#endif
