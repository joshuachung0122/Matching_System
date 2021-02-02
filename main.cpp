#include <iostream>
#include "tutor.h"
#include "student.h"
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;
//enum class Sex{M,F};
//enum class Subject{
//    CHIN,
//    ENG,
//    MATH_C,
//    MATH_E,
//    M1,
//    M2,
//    LS_C,
//    LS_E,
//    PHYS_C,
//    PHYS_E,
//    CHEM_C,
//    CHEM_E,
//    BIO_C,
//    BIO_E,
//    GEOG_C,
//    GEOG_E,
//    C_HISTORY,
//    W_HISTORY,
//    ICT,
//    ECON,
//    BAFS,
//    ACCOUNT,
//    IS,
//    CHINLIT,
//    ENGLIT,
//    VA
//};
//enum class Grade{
//    P1,
//    P2,
//    P3,
//    P4,
//    P5,
//    P6,
//    S1,
//    S2,
//    S3,
//    S4,
//    S5,
//    S6
//};
//enum class Location{
//    SHEUNG_SHUI,
//    YUEN_LONG,
//    SIU_HONG,
//    LAMMA_ISLAND,
//    HANG_HAU,
//    PENG_CHAU,
//    TAI_WAI,
//    TAI_PO,
//    LANTAU_ISLAND,
//    TAI_SHUI_HANG,
//    TAI_WO_HAU,
//    TIN_SHUI_WAI,
//    TAI_WO,
//    PO_LAM,
//    TSEUNG_KWAN_O,
//    SIU_LEK_YUEN,
//    TUEN_MUN,
//    LOHAS_PARK,
//    HENG_ON,
//    DISCOVERY_BAY,
//    TAK_KU_LING,
//    LONG_PING,
//    TUNG_CHUNG,
//    LEI_MUK_SHUE,
//    SUNNY_BAY,
//    SHA_TIN,
//    SHA_TIN_WAI,
//    SHA_TAU_KOK,
//    YAU_TONG,
//    HUNG_SHUI_KIU,
//    SHAM_TSENG,
//    CLEAR_WATER_BAY,
//    FO_TAN,
//    WU_KAI_SHA,
//    SHEK_LEI,
//    SHEK_YAM,
//    SHEK_MUN,
//    WO_CHE,
//    CITY_ONE,
//    FANLING,
//    TSUEN_WAN,
//    LAI_KING,
//    KWAI_CHUNG,
//    KWAI_SHING,
//    KWAI_HING,
//    KWAI_FONG,
//    LAM_TIN,
//    SAI_KUNG,
//    TIU_KING_LING,
//    CHE_KUNG_MIU,
//    KAM_SHEUNG_ROAD,
//    CHEUNG_CHAU,
//    TSING_YI,
//    TSING_LUNG_TAU,
//    HIN_KENG,
//    MA_LIU_SHUI,
//    MA_WAN,
//    MA_ON_SHAN,
//    KOWLOON_CITY,
//    KOWLOON_TONG,
//    KOWLOON_BAY,
//    JORDAN,
//    HO_MAN_TIN,
//    NAM_CHEONG,
//    YAU_YAT_TSUEN,
//    KAI_TAK,
//    TO_KWA_WAN,
//    TAI_WO_PING,
//    TAI_KOK_TSUI,
//    PRINCE_EDWARD,
//    OLYMPIC,
//    TSIM_SHA_TSUI,
//    CHOI_HUNG,
//    TSZ_WAN_SHAN,
//    HAMMER_HILL,
//    SAN_PO_KONG,
//    MONG_KOK,
//    AUSTIN,
//    LOK_FU,
//    WANG_TAU_HOM,
//    YAU_MA_TEI,
//    SHAM_SHUI_PO,
//    NGAU_CHI_WAN,
//    NGAU_TAU_KOK,
//    SHEK_KIP_MEI,
//    SAU_MAU_PING,
//    CHUK_YUEN,
//    HUNG_HOM,
//    MEI_FU,
//    LAI_CHI_KOK,
//    SO_UK,
//    KWUN_TONG,
//    DIAMOND_HILL,
//    CHEUNG_SHA_WAN,
//    MA_TAU_WAI,
//    LEI_YUE_MUN,
//    WHAMPOA,
//    WONG_TAI_SIN,
//    SHEUNG_WAN,
//    CENTRAL,
//    LEI_TUNG,
//    NORTH_POINT,
//    MID_LEVELS,
//    KENNEDY_TOWN,
//    TAI_HANG,
//    TIN_HAU,
//    TAIKOO_SHING,
//    SIU_SAI_WAN,
//    HENG_FA_CHUEN,
//    CHAI_WAN,
//    SOUTH_HORIZONS,
//    DEEP_WATER_BAY,
//    REPULSE_BAY,
//    WAN_CHAI,
//    FORTRESS_HILL,
//    TIN_WAN,
//    SHEK_PAI_WAN,
//    SHEK_O,
//    SHAU_KEI_WAN,
//    WAH_FU,
//    POK_FU_LAM,
//    SAI_WAN_HO,
//    SAI_YING_PUN,
//    SAI_WAN,
//    STANLEY,
//    HAPPY_VALLEY,
//    ADMIRALTY,
//    CAUSEWAY_BAY,
//    TELEGRAPH_BAY,
//    ABERDEEN,
//    QUARRY_BAY,
//    AP_LEI_CHAU,
//    STAUNTON_VALLEY
//};

//void strGradeToEnumVector(vector<Grade>& enum_vec,string str,string enumType){
//    if(str=="P1")
//        enum_vec.push_back(Grade::P1);
//    else if(str=="P2")
//        enum_vec.push_back(Grade::P2);
//    else if(str=="P3")
//        enum_vec.push_back(Grade::P3);
//    else if(str=="P4")
//        enum_vec.push_back(Grade::P4);
//    else if(str=="P5")
//        enum_vec.push_back(Grade::P5);
//    else if(str=="P6")
//        enum_vec.push_back(Grade::P6);
//    else if(str=="S1")
//        enum_vec.push_back(Grade::S1);
//    else if(str=="S2")
//        enum_vec.push_back(Grade::S2);
//    else if(str=="S3")
//        enum_vec.push_back(Grade::S3);
//    else if(str=="S4")
//        enum_vec.push_back(Grade::S4);
//    else if(str=="S5")
//        enum_vec.push_back(Grade::S5);
//    else if(str=="S6")
//        enum_vec.push_back(Grade::S6);
//    else
//    {
//        cout<<"Wrong "+enumType<<endl;
//    }
//}
//void strSubjectToEnumVector(vector<Subject>& enum_vec,string str,string enumType){
//    if(str=="Chin")
//        enum_vec.push_back(Subject::CHIN);
//    else if(str=="Eng")
//        enum_vec.push_back(Subject::ENG);
//    else if(str=="Math_C")
//        enum_vec.push_back(Subject::MATH_C);
//    else if(str=="Math_E")
//        enum_vec.push_back(Subject::MATH_E);
//    else if(str=="M1")
//        enum_vec.push_back(Subject::M1);
//    else if(str=="M2")
//        enum_vec.push_back(Subject::M2);
//    else if(str=="LS_C")
//        enum_vec.push_back(Subject::LS_C);
//    else if(str=="LS_E")
//        enum_vec.push_back(Subject::LS_E);
//    else if(str=="Phys_C")
//        enum_vec.push_back(Subject::PHYS_C);
//    else if(str=="Phys_E")
//        enum_vec.push_back(Subject::PHYS_E);
//    else if(str=="Chem_C")
//        enum_vec.push_back(Subject::CHEM_C);
//    else if(str=="Chem_E")
//        enum_vec.push_back(Subject::CHEM_E);
//    else if(str=="Bio_C")
//        enum_vec.push_back(Subject::BIO_C);
//    else if(str=="Bio_E")
//        enum_vec.push_back(Subject::BIO_E);
//    else if(str=="Geog_C")
//        enum_vec.push_back(Subject::GEOG_C);
//    else if(str=="Geog_E")
//        enum_vec.push_back(Subject::GEOG_E);
//    else if(str=="C_History")
//        enum_vec.push_back(Subject::C_HISTORY);
//    else if(str=="W_History")
//        enum_vec.push_back(Subject::W_HISTORY);
//    else if(str=="ICT")
//        enum_vec.push_back(Subject::ICT);
//    else if(str=="ECON")
//        enum_vec.push_back(Subject::ECON);
//    else if(str=="BAFS")
//        enum_vec.push_back(Subject::BAFS);
//    else if(str=="Account")
//        enum_vec.push_back(Subject::ACCOUNT);
//    else if(str=="IS")
//        enum_vec.push_back(Subject::IS);
//    else if(str=="ChinLit")
//        enum_vec.push_back(Subject::CHINLIT);
//    else if(str=="EngLit")
//        enum_vec.push_back(Subject::ENGLIT);
//    else if(str=="VA")
//        enum_vec.push_back(Subject::VA);
//    else
//    {
//        cout<<"Wrong "+enumType<<endl;
//    }
//}
//void strLocationToEnumVector(vector<Location>& enum_vec,string str,string enumType){
//    if(str=="SHEUNG_SHUI")
//        enum_vec.push_back(Location::SHEUNG_SHUI);
//    else if(str=="YUEN_LONG")
//        enum_vec.push_back(Location::YUEN_LONG);
//    else if(str=="SIU_HONG")
//        enum_vec.push_back(Location::SIU_HONG);
//    else if(str=="LAMMA_ISLAND")
//        enum_vec.push_back(Location::LAMMA_ISLAND);
//    else if(str=="HANG_HAU")
//        enum_vec.push_back(Location::HANG_HAU);
//    else if(str=="PENG_CHAU")
//        enum_vec.push_back(Location::PENG_CHAU);
//    else if(str=="TAI_WAI")
//        enum_vec.push_back(Location::TAI_WAI);
//    else if(str=="TAI_PO")
//        enum_vec.push_back(Location::TAI_PO);
//    else if(str=="LANTAU_ISLAND")
//        enum_vec.push_back(Location::LANTAU_ISLAND);
//    else if(str=="TAI_SHUI_HANG")
//        enum_vec.push_back(Location::TAI_SHUI_HANG);
//    else if(str=="TAI_WO_HAU")
//        enum_vec.push_back(Location::TAI_WO_HAU);
//    else if(str=="TIN_SHUI_WAI")
//        enum_vec.push_back(Location::TIN_SHUI_WAI);
//    else if(str=="TAI_WO")
//        enum_vec.push_back(Location::TAI_WO);
//    else if(str=="PO_LAM")
//        enum_vec.push_back(Location::PO_LAM);
//    else if(str=="TSEUNG_KWAN_O")
//        enum_vec.push_back(Location::TSEUNG_KWAN_O);
//    else if(str=="SIU_LEK_YUEN")
//        enum_vec.push_back(Location::SIU_LEK_YUEN);
//    else if(str=="TUEN_MUN")
//        enum_vec.push_back(Location::TUEN_MUN);
//    else if(str=="LOHAS_PARK")
//        enum_vec.push_back(Location::LOHAS_PARK);
//    else if(str=="HENG_ON")
//        enum_vec.push_back(Location::HENG_ON);
//    else if(str=="DISCOVERY_BAY")
//        enum_vec.push_back(Location::DISCOVERY_BAY);
//    else if(str=="TAK_KU_LING")
//        enum_vec.push_back(Location::TAK_KU_LING);
//    else if(str=="LONG_PING")
//        enum_vec.push_back(Location::LONG_PING);
//    else if(str=="TUNG_CHUNG")
//        enum_vec.push_back(Location::TUNG_CHUNG);
//    else if(str=="LEI_MUK_SHUE")
//        enum_vec.push_back(Location::LEI_MUK_SHUE);
//    else if(str=="SUNNY_BAY")
//        enum_vec.push_back(Location::SUNNY_BAY);
//    else if(str=="SHA_TIN")
//        enum_vec.push_back(Location::SHA_TIN);
//    else if(str=="SHA_TIN_WAI")
//        enum_vec.push_back(Location::SHA_TIN_WAI);
//    else if(str=="SHA_TAU_KOK")
//        enum_vec.push_back(Location::SHA_TAU_KOK);
//    else if(str=="YAU_TONG")
//        enum_vec.push_back(Location::YAU_TONG);
//    else if(str=="HUNG_SHUI_KIU")
//        enum_vec.push_back(Location::HUNG_SHUI_KIU);
//    else if(str=="SHAM_TSENG")
//        enum_vec.push_back(Location::SHAM_TSENG);
//    else if(str=="CLEAR_WATER_BAY")
//        enum_vec.push_back(Location::CLEAR_WATER_BAY);
//    else if(str=="FO_TAN")
//        enum_vec.push_back(Location::FO_TAN);
//    else if(str=="WU_KAI_SHA")
//        enum_vec.push_back(Location::WU_KAI_SHA);
//    else if(str=="SHEK_LEI")
//        enum_vec.push_back(Location::SHEK_LEI);
//    else if(str=="SHEK_YAM")
//        enum_vec.push_back(Location::SHEK_YAM);
//    else if(str=="WO_CHE")
//        enum_vec.push_back(Location::WO_CHE);
//    else if(str=="CITY_ONE")
//        enum_vec.push_back(Location::CITY_ONE);
//    else if(str=="FANLING")
//        enum_vec.push_back(Location::FANLING);
//    else if(str=="TSUEN_WAN")
//        enum_vec.push_back(Location::TSUEN_WAN);
//    else if(str=="LAI_KING")
//        enum_vec.push_back(Location::LAI_KING);
//    else if(str=="KWAI_CHUNG")
//        enum_vec.push_back(Location::KWAI_CHUNG);
//    else if(str=="KWAI_SHING")
//        enum_vec.push_back(Location::KWAI_SHING);
//    else if(str=="KWAI_HING")
//        enum_vec.push_back(Location::KWAI_HING);
//    else if(str=="KWAI_FONG")
//        enum_vec.push_back(Location::KWAI_FONG);
//    else if(str=="LAM_TIN")
//        enum_vec.push_back(Location::LAM_TIN);
//    else if(str=="SAI_KUNG")
//        enum_vec.push_back(Location::SAI_KUNG);
//    else if(str=="TIU_KING_LING")
//        enum_vec.push_back(Location::TIU_KING_LING);
//    else if(str=="CHE_KUNG_MIU")
//        enum_vec.push_back(Location::CHE_KUNG_MIU);
//    else if(str=="KAM_SHEUNG_ROAD")
//        enum_vec.push_back(Location::KAM_SHEUNG_ROAD);
//    else if(str=="CHEUNG_CHAU")
//        enum_vec.push_back(Location::CHEUNG_CHAU);
//    else if(str=="TSING_YI")
//        enum_vec.push_back(Location::TSING_YI);
//    else if(str=="TSING_LUNG_TAU")
//        enum_vec.push_back(Location::TSING_LUNG_TAU);
//    else if(str=="HIN_KENG")
//        enum_vec.push_back(Location::HIN_KENG);
//    else if(str=="MA_LIU_SHUI")
//        enum_vec.push_back(Location::MA_LIU_SHUI);
//    else if(str=="MA_WAN")
//        enum_vec.push_back(Location::MA_WAN);
//    else if(str=="MA_ON_SHAN")
//        enum_vec.push_back(Location::MA_ON_SHAN);
//    else if(str=="KOWLOON_CITY")
//        enum_vec.push_back(Location::KOWLOON_CITY);
//    else if(str=="KOWLOON_TONG")
//        enum_vec.push_back(Location::KOWLOON_TONG);
//    else if(str=="KOWLOON_BAY")
//        enum_vec.push_back(Location::KOWLOON_BAY);
//    else if(str=="JORDAN")
//        enum_vec.push_back(Location::JORDAN);
//    else if(str=="HO_MAN_TIN")
//        enum_vec.push_back(Location::HO_MAN_TIN);
//    else if(str=="NAM_CHEONG")
//        enum_vec.push_back(Location::NAM_CHEONG);
//    else if(str=="YAU_YAT_TSUEN")
//        enum_vec.push_back(Location::YAU_YAT_TSUEN);
//    else if(str=="KAI_TAK")
//        enum_vec.push_back(Location::KAI_TAK);
//    else if(str=="TO_KWA_WAN")
//        enum_vec.push_back(Location::TO_KWA_WAN);
//    else if(str=="TAI_WO_PING")
//        enum_vec.push_back(Location::TAI_WO_PING);
//    else if(str=="TAI_KOK_TSUI")
//        enum_vec.push_back(Location::TAI_KOK_TSUI);
//    else if(str=="PRINCE_EDWARD")
//        enum_vec.push_back(Location::PRINCE_EDWARD);
//    else if(str=="OLYMPIC")
//        enum_vec.push_back(Location::OLYMPIC);
//    else if(str=="TSIM_SHA_TSUI")
//        enum_vec.push_back(Location::TSIM_SHA_TSUI);
//    else if(str=="CHOI_HUNG")
//        enum_vec.push_back(Location::CHOI_HUNG);
//    else if(str=="TSZ_WAN_SHAN")
//        enum_vec.push_back(Location::TSZ_WAN_SHAN);
//    else if(str=="HAMMER_HILL")
//        enum_vec.push_back(Location::HAMMER_HILL);
//    else if(str=="SAN_PO_KONG")
//        enum_vec.push_back(Location::SAN_PO_KONG);
//    else if(str=="MONG_KOK")
//        enum_vec.push_back(Location::MONG_KOK);
//    else if(str=="AUSTIN")
//        enum_vec.push_back(Location::AUSTIN);
//    else if(str=="LOK_FU")
//        enum_vec.push_back(Location::LOK_FU);
//    else if(str=="WANG_TAU_HOM")
//        enum_vec.push_back(Location::WANG_TAU_HOM);
//    else if(str=="YAU_MA_TEI")
//        enum_vec.push_back(Location::YAU_MA_TEI);
//    else if(str=="SHAM_SHUI_PO")
//        enum_vec.push_back(Location::SHAM_SHUI_PO);
//    else if(str=="NGAU_CHI_WAN")
//        enum_vec.push_back(Location::NGAU_CHI_WAN);
//    else if(str=="NGAU_TAU_KOK")
//        enum_vec.push_back(Location::NGAU_TAU_KOK);
//    else if(str=="SHEK_KIP_MEI")
//        enum_vec.push_back(Location::SHEK_KIP_MEI);
//    else if(str=="SAU_MAU_PING")
//        enum_vec.push_back(Location::SAU_MAU_PING);
//    else if(str=="CHUK_YUEN")
//        enum_vec.push_back(Location::CHUK_YUEN);
//    else if(str=="HUNG_HOM")
//        enum_vec.push_back(Location::HUNG_HOM);
//    else if(str=="MEI_FU")
//        enum_vec.push_back(Location::MEI_FU);
//    else if(str=="LAI_CHI_KOK")
//        enum_vec.push_back(Location::LAI_CHI_KOK);
//    /*else if(str=="SO_UK")
//        enum_vec.push_back(Location::SO_UK);
//    else if(str=="KWUN_TONG")
//        enum_vec.push_back(Location::KWUN_TONG);
//    else if(str=="DIAMOND_HILL")
//        enum_vec.push_back(Location::DIAMOND_HILL);
//    else if(str=="CHEUNG_SHA_WAN")
//        enum_vec.push_back(Location::CHEUNG_SHA_WAN);
//    else if(str=="MA_TAU_WAI")
//        enum_vec.push_back(Location::MA_TAU_WAI);
//    else if(str=="LEI_YUE_MUN")
//        enum_vec.push_back(Location::LEI_YUE_MUN);
//    else if(str=="WHAMPOA")
//        enum_vec.push_back(Location::WHAMPOA);
//    else if(str=="WONG_TAI_SIN")
//        enum_vec.push_back(Location::WONG_TAI_SIN);
//    else if(str=="SHEUNG_WAN")
//        enum_vec.push_back(Location::SHEUNG_WAN);
//    else if(str=="CENTRAL")
//        enum_vec.push_back(Location::CENTRAL);
//    else if(str=="LEI_TUNG")
//        enum_vec.push_back(Location::LEI_TUNG);
//    else if(str=="NORTH_POINT")
//        enum_vec.push_back(Location::NORTH_POINT);
//    else if(str=="MID_LEVELS")
//        enum_vec.push_back(Location::MID_LEVELS);
//    else if(str=="KENNEDY_TOWN")
//        enum_vec.push_back(Location::KENNEDY_TOWN);
//    else if(str=="TAI_HANG")
//        enum_vec.push_back(Location::TAI_HANG);
//    else if(str=="TIN_HAU")
//        enum_vec.push_back(Location::TIN_HAU);
//    else if(str=="TAIKOO_SHING")
//        enum_vec.push_back(Location::TAIKOO_SHING);
//    else if(str=="SIU_SAI_WAN")
//        enum_vec.push_back(Location::SIU_SAI_WAN);
//    else if(str=="HENG_FA_CHUEN")
//        enum_vec.push_back(Location::HENG_FA_CHUEN);
//    else if(str=="SOUTH_HORIZONS")
//        enum_vec.push_back(Location::SOUTH_HORIZONS);
//    else if(str=="DEEP_WATER_BAY")
//        enum_vec.push_back(Location::DEEP_WATER_BAY);
//    else if(str=="REPULSE_BAY")
//        enum_vec.push_back(Location::REPULSE_BAY);
//    else if(str=="WAN_CHAI")
//        enum_vec.push_back(Location::WAN_CHAI);
//    else if(str=="FORTRESS_HILL")
//        enum_vec.push_back(Location::FORTRESS_HILL);
//    else if(str=="TIN_WAN")
//        enum_vec.push_back(Location::TIN_WAN);
//    else if(str=="SHEK_PAI_WAN")
//        enum_vec.push_back(Location::SHEK_PAI_WAN);
//    else if(str=="SHEK_O")
//        enum_vec.push_back(Location::SHEK_O);
//    else if(str=="SHAU_KEI_WAN")
//        enum_vec.push_back(Location::SHAU_KEI_WAN);
//    else if(str=="WAH_FU")
//        enum_vec.push_back(Location::WAH_FU);
//    else if(str=="POK_FU_LAM")
//        enum_vec.push_back(Location::POK_FU_LAM);
//    else if(str=="SAI_WAN_HO")
//        enum_vec.push_back(Location::SAI_WAN_HO);
//    else if(str=="SAI_YING_PUN")
//        enum_vec.push_back(Location::SAI_YING_PUN);
//    else if(str=="SAI_WAN")
//        enum_vec.push_back(Location::SAI_WAN);
//    else if(str=="STANLEY")
//        enum_vec.push_back(Location::STANLEY);
//    else if(str=="HAPPY_VALLEY")
//        enum_vec.push_back(Location::HAPPY_VALLEY);
//    else if(str=="ADMIRALTY")
//        enum_vec.push_back(Location::ADMIRALTY);
//    else if(str=="CAUSEWAY_BAY")
//        enum_vec.push_back(Location::CAUSEWAY_BAY);
//    else if(str=="TELEGRAPH_BAY")
//        enum_vec.push_back(Location::TELEGRAPH_BAY);
//    else if(str=="ABERDEEN")
//        enum_vec.push_back(Location::ABERDEEN);
//    else if(str=="QUARRY_BAY")
//        enum_vec.push_back(Location::QUARRY_BAY);
//    else if(str=="AP_LEI_CHAU")
//        enum_vec.push_back(Location::AP_LEI_CHAU);
//    else if(str=="STAUNTON_VALLEY")
//        enum_vec.push_back(Location::STAUNTON_VALLEY);
//    else{
//        cout<<"Wrong "+enumType<<endl;
//    }*/
//}

void splitBy(string src, vector<string>&splitedStr,char sep){
    size_t startpos = 0;
    size_t endpos = src.find(sep,startpos);
    while(endpos!=string::npos){
        splitedStr.push_back(src.substr(startpos,endpos-startpos));
        startpos = endpos+1;
        endpos = src.find(sep,startpos);
    }
    splitedStr.push_back(src.substr(startpos,src.size()-startpos));
}

void matchStudent(map<Student,vector<Tutor>>&matchList,const char* line, map<string, map<string, map<string, map<string, vector<Tutor>>>>>& tutors){
    //split the line into data
    string line_s = line;
    vector<string> data;
    splitBy(line_s,data,'\t');

    //***set targetTutorSex***//
    vector<string> targetTutorSex;
    splitBy(data[3], targetTutorSex, ',');
    
    //***set Student's grade***//
    string studentGrade = data[4];
    
    //set subjects
    vector<string>studentSubjects;
    splitBy(data[5],studentSubjects,',');

    //set locations
    vector<string>studentLocations;
    splitBy(data[6],studentLocations,',');
    
    Student newStudent(data[0],
                        data[1],
                        data[2],
                        data[3],
                        data[4],
                        data[5],
                        data[6],
                        data[7]);

    vector<Tutor>matchedTutors;
    for(int i=0;i<targetTutorSex.size();++i){
        for(int j=0;j<studentSubjects.size();++j){
            for(int k=0;k<studentLocations.size();++k){
                for(int l=0;l<tutors[targetTutorSex[i]][studentSubjects[j]][studentLocations[k]][studentGrade].size();++l){
                    matchedTutors.push_back(tutors[targetTutorSex[i]][studentSubjects[j]][studentLocations[k]][studentGrade][l]);

                }
            }
        }
    }
    if(matchedTutors.size()>0)
        matchList[newStudent] = matchedTutors;
    
}

void addTutor(map<string, map<string, map<string, map<string, vector<Tutor>>>>>&tutors,const char* line){
    string line_s = line;
    vector<string> data;
    splitBy(line_s,data,'\t');
    //***convert data from string to specific types***//
    //convert sex
    string sex = data[2];

    //convert grades
    vector<string>grades;
    splitBy(data[7],grades,',');

    //convert subjects
    vector<string>subjects;
    splitBy(data[8],subjects,',');

     //convert locations
    vector<string>locations;
    splitBy(data[9],locations,',');

    Tutor newTutor(data[0],
                    data[1],
                    data[2],
                    data[3],
                    data[4],
                    data[5],
                    data[6],
                    data[7],
                    data[8],
                    data[9],
                    data[10]);
    
    for(int i=0;i<subjects.size();++i){
        for(int j=0;j<locations.size();++j){
            for(int k=0;k<grades.size();++k)
                tutors[sex][subjects[i]][locations[j]][grades[k]].push_back(newTutor);
        }
    }

}

int main(){
    ifstream ifsTutors("tutor_info.txt");
    ifstream ifsStudents("student_info.txt");
    char line[1024];
    int numTutor = 0;
    ifsTutors.getline(line, 1024, '\n');
    map<string,map<string,map<string,map<string,vector<Tutor>>>>> tutors;
    map<Student,vector<Tutor>> matchList;

    
    for(;!ifsTutors.eof();++numTutor){
        ifsTutors.getline(line,1024,'\n');
        addTutor(tutors,line); 
    }

    int numStudent=0;
    ifsStudents.getline(line,1024,'\n');
    for(;!ifsStudents.eof();++numStudent){
        ifsStudents.getline(line,1024,'\n');
        matchStudent(matchList,line,tutors);
    }
    
    for(map<Student,vector<Tutor>>::const_iterator it=matchList.begin();it!=matchList.end();++it){
        cout<<"*****Matched Student: *****"<<endl;
        it->first.print();
        cout<<"*****Matched Tutors: *****"<<endl;
        for(int i=0;i<it->second.size();++i)
            it->second[i].print();
        cout<<endl;
    }
    ifsStudents.close();
    ifsTutors.close();
    return 0;
}