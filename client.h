#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "common.h"

/*
   ������ 
  
      programed by ������ v0.0.1
	   
  Date : 2016. 12. 1.
  Update : 2016. 12. 1
  Remarks ..  

*/

void joinClient(); //ȸ�� ����ü �����͹迭�� ����
CLIENT *regClient(); //ȸ�������� ������ ���� 
void listClient();//ȸ�� ��� 
void updateinfo();// ������������ 
void bye();//ȸ�� Ż�� 
void booksrch();//���� �˻� 
int schmenu();//�����˻��޴� 
void borrowlist();//�� �뿩��� 
int borrowcheck();//���ϰ�
int reID();//���̵� �ߺ� Ȯ�� ���� 
#endif
