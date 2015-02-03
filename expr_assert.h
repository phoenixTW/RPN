#ifndef assert
#define assert(EXPR) if(assert_expr(EXPR,__FILE__,__LINE__,#EXPR)) return
#define assertEqual(EXPR1, EXPR2) if(assert_equal(EXPR1,EXPR2,__FILE__,__LINE__,#EXPR1,#EXPR2)) return
#endif
int assert_expr(int expr,const char*,int,const char*);
int assert_equal(int,int,const char*,int,const char*,const char*);