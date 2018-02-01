#include "common.h"
#include "file.h"
#include "stdio.h"

//전역변수 
extern BOOK **book;//도서 
extern int numofbook; //도서수 

//전역변수 
extern CLIENT **client;  //회원 
extern int numofclient;  //회원수 

//전역변수
extern BORROW **borrow;//대여 
extern int numofborrow; //대여수 

void file(){
	FILE *fclient;
	FILE *fbook;
	FILE *fborrow;
	int f,b,fb;
	
	fclient=fopen("client.txt","w");
	if(fclient==NULL){
		printf("파일 개방 실패.\n");
		return ;
	}
	for(f=0; f<numofclient; f++){		
		fprintf(fclient, "%s %s %s %s %s %s\n",
		client[f]->clientNum,client[f]->clientPw,client[f]->clientName,client[f]->clientAddr,client[f]->clientPhone,client[f]->clientId);
	}
	fclose(fclient);


	fbook=fopen("book.txt","w");
	if(fbook==NULL){
		printf("파일 개방 실패.\n");
		return ;
	}
	for(b=0; b<numofbook; b++){		
		fprintf(fbook, "%s %s %s %s %s %d\n",
		book[b]->bookName,book[b]->bookPublisher,book[b]->bookWriter,book[b]->bookISBN,book[b]->bookHolding,book[b]->rent);
	}
	fclose(fbook);
	
	
	fborrow=fopen("borrow.txt","w");
	if(fborrow==NULL){
		printf("파일 개방 실패.\n");
		return ;
	}
	for(fb=0; fb<numofborrow; fb++){
		fprintf(fborrow, "%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d\n",
		borrow[fb]->bADMIN,borrow[fb]->bisbN,borrow[fb]->bnamE,borrow[fb]->bYear,borrow[fb]->bMon,borrow[fb]->bDay,borrow[fb]->bHour,borrow[fb]->bMin,borrow[fb]->bSec,
		borrow[fb]->reYear,borrow[fb]->reMon,borrow[fb]->reDay,borrow[fb]->reHour,borrow[fb]->reMin,borrow[fb]->reSec);
		}
	fclose(fborrow);
	
	return ;
}

void Clientwrt(){
	
	FILE *fclient=fopen("client.txt","r");
	CLIENT *temp;
	
	if(fclient!=NULL){	
		while(1){
			if(numofclient==0){
				client=(CLIENT **)malloc(sizeof(CLIENT*));
			}
			else{
				client=(CLIENT **)realloc(client, (numofclient+1)*sizeof(CLIENT*));
			}
			temp=copen(fclient);
			if(strcmp(temp->clientNum,"end")==0 ){
				break;
			}else{
				client[numofclient++]=temp;
			}
		}
	}
	fclose(fclient);
}
CLIENT *copen(FILE *fclient){
	int res;
	CLIENT *FClient=(CLIENT *)malloc(sizeof(CLIENT)); 
	
	res=fscanf(fclient,"%s %s %s %s %s %s",
	    FClient->clientNum,FClient->clientPw,FClient->clientName,FClient->clientAddr,FClient->clientPhone,FClient->clientId);
	if(res==EOF){
		strcpy(FClient->clientNum,"end");
		
	}
	
	return FClient;
}
void Bookwrt(){
	FILE *fbook=fopen("book.txt","r");
	BOOK *temp;
	if(fbook!=NULL){
		while(1){
			if(numofbook==0){
				book=(BOOK **)malloc(sizeof(BOOK*));
			}
			else{
				book=(BOOK **)realloc(book, (numofbook+1)*sizeof(BOOK*));
			}
			temp=bopen(fbook);
			if(strcmp(temp->bookName,"end")==0){
				break;
			}else{
				book[numofbook++]=temp;
			}
		}
	}
	fclose(fbook);
}
BOOK *bopen(FILE *fbook){
	int res;
	BOOK *FBook=(BOOK *)malloc(sizeof(BOOK));
	
	res=fscanf(fbook,"%s %s %s %s %s %d",
		FBook->bookName,FBook->bookPublisher,FBook->bookWriter,FBook->bookISBN,FBook->bookHolding,&FBook->rent);
	if(res==EOF){
		strcpy(FBook->bookName,"end");
	}
	return FBook;
}
void Borrowwrt(){
	FILE *fborrow=fopen("borrow.txt","r");
	BORROW *temp;
	if(fborrow!=NULL){
		while(1){
			if(numofborrow==0){
				borrow=(BORROW **)malloc(sizeof(BORROW*));
			}else{
				borrow=(BORROW **)realloc(borrow, (numofborrow+1)*sizeof(BORROW*));
			}
			temp=ropen(fborrow);
			if(strcmp(temp->bADMIN,"end")==0){
				break;
			}else{
				borrow[numofborrow++]=temp;
			}
		}
	}
	fclose(fborrow);
}
BORROW *ropen(FILE *fborrow){
	int res;
	BORROW *FBorrow=(BORROW *)malloc(sizeof(BORROW));
	
	res=fscanf(fborrow, "%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d\n",
		FBorrow->bADMIN,FBorrow->bisbN,FBorrow->bnamE,&FBorrow->bYear,&FBorrow->bMon,&FBorrow->bDay,&FBorrow->bHour,&FBorrow->bMin,&FBorrow->bSec,
		&FBorrow->reYear,&FBorrow->reMon,&FBorrow->reDay,&FBorrow->reHour,&FBorrow->reMin,&FBorrow->reSec);
	if(res==EOF){
		strcpy(FBorrow->bADMIN,"end");
	}
	return FBorrow;	
}
