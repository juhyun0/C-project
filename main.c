#include "common.h"
#include "menu.h"
#include "file.h"

//�������� 
CLIENT **client;  //ȸ�� 
int numofclient=0;  //ȸ���� 
char g_userID[20]; 

BOOK **book;//���� 
int numofbook=0; //������

BORROW **borrow;//�뿩 
int numofborrow=0; //�뿩�� 

int main() {

    MAINMNU m;	
    
    client=(CLIENT **)malloc(sizeof(CLIENT *));  // ȸ������ü �����͹迭 �����Ҵ�  *client[0] 
    borrow=(BORROW **)malloc(sizeof(BORROW *));  // �뿩��ϱ���ü �����͹迭 �����Ҵ�  *borrow[0] 
    book=(BOOK **)malloc(sizeof(BOOK *));  // �뿩��ϱ���ü �����͹迭 �����Ҵ�  *book[0] 
    
	Clientwrt();
    Bookwrt();
    Borrowwrt();
    
    while((m=mainmenu())!=QUIT){
    	switch(m){
    		case JOIN:
    			joinClient();
    			break;
    		case LOGIN :
    			login();
    			break;
    		default :
    			MenuError();
    			break;
    	}
    }
    
    listClient();
	file();
	
	return 0;
}
