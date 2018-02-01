#ifndef _FILE_H_
#define _FILE_H_

void file();
void Clientwrt();
void Bookwrt();
void Borrowwrt();
CLIENT *copen(FILE *fclient);
BOOK *bopen();
BORROW *ropen();
#endif
