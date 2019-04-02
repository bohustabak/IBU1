
#include "main.h"
#include "..\fsm\fsm.h"

Flat ast = {fsm_Ltoilet, fsm_Lbath, fsm_Llobby, fsm_Lkitchen, fsm_Lwardrobe};

void STM_vInit(){
  Fsm fsm_Ltoilet;
  Fsm fsm_Lbath;
  Fsm fsm_Llobby;
  Fsm fsm_Lkitchen;
  Fsm fsm_Lwardrobe;
}
  

void STM_vHandleTask(){
  ast.trigger(5);
}
