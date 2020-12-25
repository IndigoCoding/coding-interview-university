/* Edit distance full version with edit action traceback ability + robust function */
enum operation{MATCH, INSERT, DELETE};

typedef struct {
    int cost;
    int parent;
} cell;

int EditDistance(char*, char*);
void rowInit(cell**, int);
void columnInit(cell**, int);
int match(char, char);
int indel(char);
void goalCell(char*, char*, int*, int*);
void reconstructPath(cell**, char*, char*, int, int);
void matchOut(char*, char*, int, int);
void insertOut(char*, int);
void deleteOut(char*, int);