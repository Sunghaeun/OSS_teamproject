#include <stdio.h>
#include "menu.h"
#include "other.h"
#include "CRUD.h"
//main 함수
int main(void) {
  file_import();
  
  int menu = menu();
  while(1){
    which(menu){
      case 0: 
        file_store();
        return 0;

      case 1:
        seat_create();
        break;

      case 2:
        seat_read();
        break;

      case 3:
        seat_change();
        break;

      case 4:
        seat_delete();
        break;

      case 5:
        searchName();
        break;

      case 6:
        timeAdd();
        break;

      case 7:
        orderFood();
        break;

      case 8:
        report_seat();
        break;

      default:
       break;
    }
  }
  return 0;
}


/*
int main(void){
    
    Product slist[100];
    int curcount=0;
    int count = 0, menu;
    
    count = loadData(slist);
    curcount=count; 

    while (1){
        menu = selectMenu();
        getchar();
        if(menu == 0) break;
        if(menu == 1 || menu ==3 || menu == 4){	
		    if (count==0){ 
                printf(" 데이터가 없습니다!\n");
			    continue;
			}
		}

        if(menu == 1) listProduct(slist,curcount); 
        else if (menu == 2) {
            count+=createProduct(&slist[curcount++]); 
        }
        else if (menu == 3) {
            int no=selectDataNo(slist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            updateProduct(&slist[no-1]);
        }
        else if (menu == 4) {
            int no=selectDataNo(slist, curcount);
            if(no==0){
                printf("=>취소됨!");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제:1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteProduct(&slist[no-1])) count --;       
           	 } 
        }
	    else if (menu == 5){
		    if (count==0) printf("데이터가 없습니다!\n");
		    else saveData(slist,curcount);
	    }
	}

	printf("\n종료됨!\n");
   	return 0;
}*/
