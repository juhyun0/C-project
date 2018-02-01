#ifndef _COMMON_H_ 
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
  ȸ��, ����, �뿩����ü
  
      programed by ������ v0.0.1
	   
  Date : 2016. 12. 1.
  Update : 2016. 12. 1
  Remarks ..  

*/
#define ADMINID "admin"
#define ADMINPW "0000"
#define MenuError() printf("�޴����ÿ���!\n") 


// ���θ޴� ������ JOIN : ȸ������, LOGIN : �α��� , QUIT : ���α׷� ���� 
typedef enum Mainmenu { JOIN=1, LOGIN, QUIT } MAINMNU;

typedef enum Clientmenu { BOOKSRCH=1, BORROWLIST, UPDATEINFO, BYE, LOGOUT, EXIT } CLIENTMNU;
typedef enum Adminmenu { BOOKRGT=1, BOOKDEL, BOOKRENT, BOOKRET, BOOKSerRCH, CLIENTLIST, BOOLOGOUT, OUT } ADMINMNU;

//ȸ�� ��� ����ü 
typedef struct client{
	char clientNum[10]; // �й� 
	char clientPw[20]; //��й�ȣ
	char clientName[10]; //�̸�
	char clientAddr[80]; //�ּ�
	char clientPhone[20]; //��ȭ��ȣ 
	char clientId[20];//���̵� 
}CLIENT;

//���� ��� ����ü 
typedef struct book{
	char bookName[20]; //������ 
	char bookPublisher[15]; //���ǻ� 
	char bookWriter[15]; //���ڸ�
	char bookISBN[15]; //ISBN
	char bookHolding[15]; //����ó 
	char bookRent[15]; //�뿩���� ���� 
	int rent; 
}BOOK;
//���� �뿩 ����ü 
typedef struct borrow{
	char bADMIN[20]; //�����ID 
	char bisbN[20]; //������ȣ ISBN
	char bnamE[20];//������
	int bYear; //(�뿩����)�� 
	int bMon; //(�뿩����)��
	int bDay; //(�뿩����)�� 
	int bHour; //(�뿩����)�� 
	int bMin; //(�뿩����)��
	int bSec; //(�뿩����)�� 
	int reYear; //(�ݳ�����)��
	int reMon; //(�ݳ�����)��
	int reDay; //(�ݳ�����)�� 
	int reHour; //(�ݳ�����)�� 
	int reMin; //(�ݳ�����)�� 
	int reSec; //(�ݳ�����)�� 
	int brent;//�����ݳ����� �뿩1,�ݳ�0 
}BORROW;
 

#endif
