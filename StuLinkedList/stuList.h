/*stuList.h*/
struct StuInfo
{
    int nosense;
    int myid;
    char name[20];
    char sex[20];    //w = female; m = male;
};

//Student's score
struct StuScore
{
    int chinese;
    int math;
    int english;
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
//getData
void getData(node * current);

//Create and record the data;
//n == max number of students;
node * creatAList(int n);

node * deleteAnode(node * head, int nodeId);

void printAList(node * head);

//insert a node inside some ids(��������������ĳ�����һ������ڵ�)
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
