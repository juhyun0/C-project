#include "common.h"
#include "menu.h"
#include "client.h"

//�������� 
extern CLIENT **client;  //ȸ�� 
extern int numofclient;  //ȸ���� 

//�������� 
extern BOOK **book;//���� 
extern int numofbook; //������ 

//��������
extern BORROW **borrow;//�뿩 
extern int numofborrow; //�뿩�� 

extern char g_userID[20]; 

int mainmenu(){
	int mnu; 

	printf("\n\t>> ������ ���� ver0.0.1 <<\n\n");
		 
	printf("1. ȸ������\n"); 
	printf("2. �α���\n"); 
	printf("3. ���α׷� ����\n");
	printf(">> ");
	
	scanf("%d",&mnu);
	
	return mnu; 
}

int client_menu(){
	int cmnu;
	
	printf(" >> ȸ�� �޴�<< \n");
	
	printf("1. ���� �˻�\n");
	printf("2. �뿩 ���\n"); 
	printf("3. ������������\n"); 
	printf("4. ȸ�� Ż��\n"); 
	printf("5. �α׾ƿ�\n"); 
	printf("6. ���α׷� ����\n");
	printf(">> ");
	
	scanf("%d",&cmnu);
	
	return cmnu;  
}

void clientMain(){
	CLIENTMNU cm;
	 
	while((cm=client_menu())!=LOGOUT){

		switch(cm) {
           case BOOKSRCH:
           		booksrch();
           	    break;
		   case BORROWLIST:
		   		borrowlist();
		   		break;
		   case UPDATEINFO:
		 		updateinfo();
		   		break;
		   case BYE:
		   		bye();
		   		file();
		   		break;
		   case EXIT: exit(0);
		   		break;
		   default : MenuError();
		   		break;
		}
	}

}

int admin_menu(){
	int amnu;
	
	printf(" >> ������ �޴�<< \n");
	
	printf("1. ���� ���\n");
	printf("2. ���� ����\n"); 
	printf("3. ���� �뿩\n"); 
	printf("4. ���� �ݳ�\n"); 
	printf("5. ���� �˻�\n"); 
	printf("6. ���� ���\n");
	printf("7. �α� �ƿ�\n");
	printf("8. ���α׷� ����\n");
	printf(">> ");
	
	scanf("%d",&amnu);
	
	return amnu; 
}
void adminMain(){
	ADMINMNU am;
	
	while((am=admin_menu())!=BOOLOGOUT){
		switch(am) {
           case BOOKRGT:
           		regbook();
           		file();
           	    break;
		   case BOOKDEL:
		   		bookdel();
		   		break;
		   case BOOKRENT:
		   		borbook();
		   		break;
		   case BOOKRET:
		   		bookret();
		   		break;
		   case BOOKSerRCH:
		   		bookserrch();
		   		break;	
		   case CLIENTLIST:
		   		booklist();
		   		break;
		   case OUT: exit(0);
		   		break;
		   default : MenuError();
		   		break;
		}
	}
}
void login(){ //�α��� �Լ�
	char ID[10];
	char PW[15];
	
	printf("ID : ");
	scanf("%s",ID);
	printf("Password : ");
	scanf("%s",PW);
	
	if(checkclient(ID, PW)==1){
		printf(" �α��� ����!\n");
		strcpy(g_userID,ID);
		clientMain();
		
	}
	else if(strcmp(ID,ADMINID)==0 && strcmp(PW,ADMINPW)==0){
		printf(" ������ �α��� ����!\n"); 
		adminMain();
	}
	else {
		printf(" * ȸ�������� ����ϼ���* \n"); 
	}
}
int checkclient(char *ID,char *PW){ 
	int i;
	for(i=0; i<numofclient; i++){
		if(strcmp(client[i]->clientId,ID)==0 && strcmp(client[i]->clientPw,PW)==0){
			return 1;
		}
	}
	
	
	return 0;
}
