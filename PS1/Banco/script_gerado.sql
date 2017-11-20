create table ALIMENTO (
BDCODALI             INTEGER                        not null,
BDDESC               VARCHAR(100),
BDPROT               NUMERIC(15,2),
BDCARBO              NUMERIC(15,2),
BDGORD               NUMERIC(15,2),
constraint PK_ALIMENTO primary key (BDCODALI)
);

create table DIETA (
BDCODDIETA           INTEGER                        not null,
BDOBJETIVO           INTEGER,
BDNECKCAL            NUMERIC(15,2),
BDNECPROT            NUMERIC(15,2),
BDNECCARB            NUMERIC(15,2),
BDNECGORD            NUMERIC(15,2),
constraint PK_DIETA primary key (BDCODDIETA)
);

create table PERFIL (
BDNOME               VARCHAR(50),
BAVALOR              VARCHAR(50)
);

create table REFEICAO (
BDCODREF             INTEGER                        not null,
BDCODTIP             INTEGER,
BDCODDIETA           INTEGER,
BDDESCREF            VARCHAR(200),
BDHORARIO            DATE,
BDLEMBRETE           VARCHAR(5),
BDNECPROT            NUMERIC(15,2),
BDNECKCAL            NUMERIC(15,2),
BDNECCARB            NUMERIC(15,2),
BDNECGORD            NUMERIC(15,2),
constraint PK_REFEICAO primary key (BDCODREF)
);

create table REFEICAO_ALIMENTO (
BDCODREF             INTEGER                        not null,
BDCODALI             INTEGER                        not null,
constraint PK_REFEICAO_ALIMENTO primary key (BDCODREF, BDCODALI)
);

create table TIPO_REFEICAO (
BDCODTIP             INTEGER                        not null,
BDDESCTIP            VARCHAR(100),
constraint PK_TIPO_REFEICAO primary key (BDCODTIP)
);

create table TIPO_REFEICAO_ALIMENTO (
BDCODALI             INTEGER                        not null,
BDCODTIP             INTEGER                        not null,
constraint PK_TIPO_REFEICAO_ALIMENTO primary key (BDCODALI, BDCODTIP)
);

alter table REFEICAO
   add constraint FK_REFEICAO_FK0001_TIPO_REF foreign key (BDCODTIP)
      references TIPO_REFEICAO (BDCODTIP);

alter table REFEICAO
   add constraint FK_REFEICAO_FK0003_DIETA foreign key (BDCODDIETA)
      references DIETA (BDCODDIETA);

alter table REFEICAO_ALIMENTO
   add constraint FK_REFEICAO_FK0005_ALIMENTO foreign key (BDCODALI)
      references ALIMENTO (BDCODALI);

alter table REFEICAO_ALIMENTO
   add constraint FK_REFEICAO_FK0006_REFEICAO foreign key (BDCODREF)
      references REFEICAO (BDCODREF);

alter table TIPO_REFEICAO_ALIMENTO
   add constraint FK_TIPO_REF_FK0002_TIPO_REF foreign key (BDCODTIP)
      references TIPO_REFEICAO (BDCODTIP);

alter table TIPO_REFEICAO_ALIMENTO
   add constraint FK_TIPO_REF_FK0004_ALIMENTO foreign key (BDCODALI)
      references ALIMENTO (BDCODALI);

