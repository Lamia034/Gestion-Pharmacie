#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>



typedef struct produit{
	char nom[30];
	int code;
	int quantite;
	float prix;
}produit;

typedef struct{
	int j,m,a;
}date;
typedef struct{
	int code_pro;
	float prixA;
	date achat_pro_date;
	int k;
}vente;

date today(){
   time_t now = time(NULL);

   struct tm *gm_time = localtime(&now);
   
   date this_day ;
   this_day.j = gm_time->tm_mday;
   this_day.m = gm_time->tm_mon+1;
   this_day.a = gm_time->tm_year+1900;
    return this_day;
}

vente vente_liste[300];


produit *p;
int x=0;
int nbr=5;
void ajouter_nouveau_produit(){
	if(x==nbr){
         nbr+=nbr;
        p = realloc(p,nbr*sizeof(produit));
     }
 	printf("entrer le nom du produit:\n");
	scanf("%s",p[x].nom);
	fflush(stdin);
	
	printf("entrer le code du produit:\n");
	scanf("%d",&p[x].code);
	
	printf("entrer la quantite du produit:\n");
	scanf("%d",&p[x].quantite);
	printf("entrer le prix du produit:\n");
	scanf("%f",&p[x].prix);
	x++;
 }
void ajouter_plusieurs_produits(int n){
  	int j;
 	for(j=0;j<n;j++){
 		ajouter_nouveau_produit();
	 }
 }
 void lister_ordre_alpha(produit *p,int x){
 	int i,j;
 	char *name;
 	float tmp;
 	produit temp;
 	for(i=0;i<x;i++){
 		for(j=i+1;j<x;j++){
 		if(strcmp(p[i].nom,p[j].nom)>0){
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
		 }
	 }}
	 	printf("\nlister par ordre alphabetique:\n");
		for(i=0;i<x;i++){
	 	printf("\n%s \n%f \nprix TTC:%f",p[i].nom,p[i].prix,(p[i].prix+0.15*p[i].prix));
	 	printf("\n***************************************\n");
	 }
}

 void lister_ordre_prix(produit *p,int x){
 	int i,j;
	 float tmp;
 	char *name;
 	produit temp;
 	 	for(i=0;i<x;i++){
 		for(j=i+1;j<x;j++){
 		if(p[i].prix < p[j].prix){
 			temp=p[i];
 			p[i]=p[j];
 			p[j]=temp;
		 }
	}
	 }
	 	printf("\nlister par ordre decroissant du prix:\n");
	 	 for(i=0;i<x;i++){
	 	printf("\n%s \n%f \nprix TTC: %f",p[i].nom,p[i].prix,(p[i].prix+0.15*p[i].prix));
	 	printf("***************************************");
	 }
 }

 int k=0;
 

 void acheter_produit(produit *p,int x){
	int i,c,q,j,n;
	float prixT;
	vente acheterpro;
		printf("\nentrer le code du med que vous voulez acheter:\n");
		scanf("%d",&c);
		printf("\nentrer la quantite :\n");
		scanf("%d",&q);
		
		 for(i=0;i<x;i++){
			if(q > p[i].quantite){
			printf("la quantite restante est seulement :%d veuillez resaisir",p[i].quantite);
			}
			else if(c == p[i].code){
				p[i].quantite = p[i].quantite - q ;
				printf("\nle nom du produit achete :%s \nla quantite restante :%d \nprix TTC totale: %f",p[i].nom,p[i].quantite,q*(p[i].prix+0.15*p[i].prix));
				
				vente_liste[k].achat_pro_date.j=today().j;
				vente_liste[k].achat_pro_date.m=today().m;
				vente_liste[k].achat_pro_date.m=today().m;
				vente_liste[k].code_pro=c;
				vente_liste[k].prixA=p[i].prix+0.15*p[i].prix;
				k++;

						}
			

	}	
}
float total_prix(){
	int i;
	float prixT=0;
	for(i=0;i<k;i++){
		if(today().j==vente_liste[i].achat_pro_date.j && vente_liste[i].achat_pro_date.m==today().m && vente_liste[i].achat_pro_date.a==today().a){
		prixT+= vente_liste[i].prixA ;//((vente_liste[i].prixA)+0.15*(vente_liste[i].prixA));
	}
	}
	printf("le prix des vends total de %d/%d/%d est %f",today().j,today().m,today().a,prixT);
	return prixT;
}
 float moyen(){
	float moy;
 	return moy=total_prix()/k;
 	
 }

float max_prix(){
	int i;
	vente max;
	max.prixA = vente_liste[0].prixA;
	for(i=1;i<k;i++){
		if(vente_liste[i].prixA > max.prixA){
			max.prixA=vente_liste[i].prixA;
		
	}
}
return max.prixA;
}

float min_prix(){
	int i;
	vente min;
	min.prixA = vente_liste[0].prixA;
	for(i=1;i<k;i++){
		if(vente_liste[i].prixA < min.prixA){
			min.prixA=vente_liste[i].prixA;
		
	}
}
return min.prixA;
}

void afficher_liste(){
	int i;
		for(i=0;i<k;i++){
			printf("vente_liste[%d]:%d",i,vente_liste[i].code_pro);
		}
}

void recherche_code_quantite(produit *p,int x){
	int i,r;
	printf("\nentrer le code ou la quantite du produit cherche:\n");
	scanf("%d",&r);
	for(i=0;i<x;i++){
		if(r == p[i].code || r == p[i].quantite){
			printf("details sur votre produit :\nnom :%s \nquantite :%d \ncode :%d \nprix TTC :%f \n",p[i].nom,p[i].quantite,p[i].code,(p[i].prix+0.15*p[i].prix));
		}
	}
}
void etat_du_stock(produit *p,int x){
	int i;
	for(i=0;i<x;i++)
		if(p[i].quantite < 3)
			printf("\nle produit nomme :%s a de quantite :%d\n",p[i].nom,p[i].quantite);

    printf("\nil n'y a aucun besoin dans les produits passés produits!\n");
		
	
}

void alimenter_stock(produit *p,int x){
	int i,c,q,j=0;
	printf("\nentrer le code du produit que vous voulez ajouter au stock:\n");
	scanf("%d",&c);
	printf("\nentrer la quantite que vous voulez ajouter\n");
	scanf("%d",&q);
	for(i=0;i<x;i++){
		if(c == p[i].code){
			p[i].quantite = p[i].quantite + q;
			j++;
		}
	}
	if(j==0){
	
			printf("\nle produit est nouveau dans notre stock !veuillez entrer ses information:\n");
			ajouter_nouveau_produit();
}
	

	
	
	 	printf("\nl'etat actuelle du stock:\n");
 			for(i=0;i<x;i++){
	 	printf("\n NOM:%s \n CODE : %d\n QUANTITE :%d\nPRIX:%.4f \nprix TTC:%.4f",p[i].nom,p[i].code,p[i].quantite,p[i].prix,(p[i].prix+0.15*p[i].prix));
	 	printf("\n***************************************\n");
	 }
	
}


void supp_produit_par_code(produit *p,int x){
	int i,j,c;
	printf("entrer le code du produit que vous voulez supprimer:");
	scanf("%d",&c);
	for(i=0;i<x;i++){
		if(c == p[i].code){
			for(j=i;j<x-1;j++){
			p[j]=p[j+1];
				
			}
		
		}
	
	 }
	}




 void affichage(){
 	int i;
 			for(i=0;i<x;i++){
	 	printf("\n NOM:%s \n PRIX:%.4f \nprix TTC:%.4f",p[i].nom,p[i].prix,(p[i].prix+0.15*p[i].prix));
	 	printf("\n***************************************\n");
	 }
 }
void menu(){
 	int  choix;
 	float prixT,moy,min,max;
	int n;
	printf("_____________________________MENU_____________________________\n");
	printf("#cliquez sur 1 pour ajouter nouveau produit \t\t\t\t");
	printf("#cliquez sur 2 pour ajouter plusieurs produit\n");	
	printf("#cliquez sur 3 pour lister les produits en ordre alphabetique \t\t");
	printf("#cliquez sur 4 pour lister les produits en ordre decroissant du prix\n");
	printf("#cliquez sur 5 pour acheter un produit \t\t\t\t\t");
	printf("#cliquez sur 6 pour rechercher un produit par code ou quantite\n");
	printf("#cliquez sur 7 pour alimenter le stock \t\t\t\t\t");
	printf("#cliquez sur 8 pour supprimer un produit par code\n");
	printf("#cliquez sur 9 pour savoir l'etat de stock \t\t\t\t\t");
	printf("#cliquez sur 10 pour afficher\n");
	printf("#cliquez sur 11 pour savoir le totale des prix des ventes \t\t\t\t\t");
	printf("#cliquez sur 12 pour afficher la liste des ventes\n");
	printf("#cliquez sur 13 pour savoir le moyen des prix des ventes \t\t\t\t\t");
	printf("#cliquez sur 14 pour afficher le max des ventes\n");
	printf("#cliquez sur 15 pour savoir le min des prix des ventes \t\t\t\t\t");
	printf("\nentrez votre choix:");
	scanf("%d",&choix);
	switch (choix){
		case 1:
			ajouter_nouveau_produit();
			menu();
			break;
		case 2:
		printf("entrer nbr de produits\n");
			scanf("%d",&n);
		    ajouter_plusieurs_produits(n);
		    menu();
			break;
		case 3:
		lister_ordre_alpha(p,x);
			menu();
			break;
		case 4:lister_ordre_prix(p,x);
		     menu();
			break;
		case 5: acheter_produit(p,x);
			menu();
			break;
		case 6:recherche_code_quantite(p,x);
			menu();
			break;
        case 7:alimenter_stock(p,x);
        		menu();
        	break;
		case 8:supp_produit_par_code(p,x);
				x--;
			menu();
			break;
		case 9:etat_du_stock(p,x);
			menu();
			break;
		case 10:
				affichage();
				menu();
				break;
		case 11:prixT=total_prix();
		       menu();
				break;
		case 12:afficher_liste();
		       menu();
			break;
		case 13:moy=moyen();
			menu();
			break;
		case 14:max=max_prix();
			menu();
			break;
		case 15:min=min_prix();
			menu();
			break;
	}
 }

int main(){
    p = malloc(nbr*sizeof(produit));
   menu();
	
	return 0;
}
