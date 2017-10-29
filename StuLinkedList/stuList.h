/*stuList.h*/
struct StuInfo
{
    char id[20];
    char name[20];
    char sex;    //w = female; m = male;
};

//Student's score
struct StuScore
{
    int chinese;
    int math;
    int English;
    float average;
};

//LinkedList
struct node
{
    struct StuInfo info;
    struct StuScore score;
    int nodeId;     //To tag each node;
    struct node * next;    //Point to the next;
};
typedef struct node node;

//Create and record the data;
node * creatAList(void);

node * deleteAnode(node * head, int nodeId);

void printAList(node * head);

//insert a node inside some ids(中文来讲就是在某序号下一个插入节点)
node * insertANode(node * head, int nodeId_before);

//So We need to reId all the nodes
//startId means whether you want to start with 1 or 0;
node * reIdList(node * head, int startId);

//calculate the average score
//return whether is successful
//the head is not changed
int calTheAve(node * head);

//Order the list
node * orderAList(node * head);
