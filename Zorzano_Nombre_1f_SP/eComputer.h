typedef struct{

    int id;
    char descripcion[256];
    float precio;
    int idTipo;

}eComputer;

eComputer* eComputer_new();
eComputer* eComputer_newParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr);
int eComputer_delete(eComputer* this);

int eComputer_setId(eComputer* this, int id);
int eComputer_setDescripcion(eComputer* this, char* descripcion);
int eComputer_setPrecio(eComputer* this, float precio);
int eComputer_setIdTipo(eComputer* this, int idTipo);

int eComputer_getId(eComputer* this);
char* eComputer_getDescripcion(eComputer* this);
float eComputer_getPrecio(eComputer* this);
int eComputer_getIdTipo(eComputer* this);

void  eComputer_showComputer(eComputer* this);
void  eComputer_showComputadora(eComputer* this);
void  eComputer_showComputers(eComputer* this);
int eComputer_comparaTipos(void* pTipo1,void* pTipo2);
float eComputer_tipoComputer(void* computer);
int  eComputer_isValidNumber(int intRecibido);
int eComputer_computersType(void* computers, int tipo);

