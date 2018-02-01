#include "common.h"
#include "menu.h"
#include "file.h"

//전역변수 
CLIENT **client;  //회원 
int numofclient=0;  //회원수 
char g_userID[20]; 

BOOK **book;//도서 
int numofbook=0; //도서수

BORROW **borrow;//대여 
int numofborrow=0; //대여수 

int main() {

    MAINMNU m;	
    
    client=(CLIENT **)malloc(sizeof(CLIENT *));  // 회원구조체 포인터배열 동적할당  *client[0] 
    borrow=(BORROW **)malloc(sizeof(BORROW *));  // 대여목록구조체 포인터배열 동적할당  *borrow[0] 
    book=(BOOK **)malloc(sizeof(BOOK *));  // 대여목록구조체 포인터배열 동적할당  *book[0] 
    
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
