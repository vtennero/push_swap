

typedef struct {
 int ra, rb, rra, rrb, sa, sb, rr, rrr, ss;
} MyStruct;

void updateStruct(MyStruct* structPtr, int minCostIndex, int cost[], int numCosts) {
 switch(minCostIndex) {
   case 0:
     structPtr->ra = max(structPtr->ra, structPtr->rb);
     break;
   case 1:
     structPtr->rra = max(structPtr->rra, structPtr->rrb);
     break;
   case 2:
     structPtr->ra = max(structPtr->ra, structPtr->rrb);
     break;
   case 3:
     structPtr->rra = max(structPtr->rra, structPtr->rb);
     break;
   default:
     break;
 }
}