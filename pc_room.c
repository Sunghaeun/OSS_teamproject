#include "pc_room.h"
//main 함수
int main(void) {
  file_import();
  
  int menu = start();
  
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
  return 0;
}
