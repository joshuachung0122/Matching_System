#include <iostream>
#include "tutor.h"
#include "student.h"
#include <list>
#include <fstream>

using namespace std;
enum class Sex{M,F};
enum class Subject{
    CHIN,
    ENG,
    MATH_C,
    MATH_E,
    M1,
    M2,
    LS_C,
    LS_E,
    PHYS_C,
    PHYS_E,
    CHEM_C,
    CHEM_E,
    BIO_C,
    BIO_E,
    GEOG_C,
    GEOG_E,
    C_HISTORY,
    W_HISTORY,
    ICT,
    ECON,
    BAFS,
    ACCOUNT,
    IS,
    CHINLIT,
    ENGLIT,
    VA
};
enum class Grade{
    P1,
    P2,
    P3,
    P4,
    P5,
    P6,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6
};
enum class Location{
    SHEUNG_SHUI,
    YUEN_LONG,
    SIU_HONG,
    LAMMA_ISLAND,
    HANG_HAU,
    PENG_CHAU,
    TAI_WAI,
    TAI_PO,
    LANTAU_ISLAND,
    TAI_SHUI_HANG,
    TAI_WO_HAU,
    TIN_SHUI_WAI,
    TAI_WO,
    PO_LAM,
    TSEUNG_KWAN_O,
    SIU_LEK_YUEN,
    TUEN_MUN,
    LOHAS_PARK,
    HENG_ON,
    DISCOVERY_BAY,
    TAK_KU_LING,
    LONG_PING,
    TUNG_CHUNG,
    LEI_MUK_SHUE,
    SUNNY_BAY,
    SHA_TIN,
    SHA_TIN_WAI,
    SHA_TAU_KOK,
    YAU_TONG,
    HUNG_SHUI_KIU,
    SHAM_TSENG,
    CLEAR_WATER_BAY,
    FO_TAN,
    WU_KAI_SHA,
    SHEK_LEI,
    SHEK_YAM,
    SHEK_MUN,
    WO_CHE,
    CITY_ONE,
    FANLING,
    TSUEN_WAN,
    LAI_KING,
    KWAI_CHUNG,
    KWAI_SHING,
    KWAI_HING,
    KWAI_FONG,
    LAM_TIN,
    SAI_KUNG,
    TIU_KING_LING,
    CHE_KUNG_MIU,
    KAM_SHEUNG_ROAD,
    CHEUNG_CHAU,
    TSING_YI,
    TSING_LUNG_TAU,
    HIN_KENG,
    MA_LIU_SHUI,
    MA_WAN,
    MA_ON_SHAN,
    KOWLOON_CITY,
    KOWLOON_TONG,
    KOWLOON_BAY,
    JORDAN,
    HO_MAN_TIN,
    NAM_CHEONG,
    YAU_YAT_TSUEN,
    KAI_TAK,
    TO_KWA_WAN,
    TAI_WO_PING,
    TAI_KOK_TSUI,
    PRINCE_EDWARD,
    OLYMPIC,
    TSIM_SHA_TSUI,
    CHOI_HUNG,
    TSZ_WAN_SHAN,
    HAMMER_HILL,
    SAN_PO_KONG,
    MONG_KOK,
    AUSTIN,
    LOK_FU,
    WANG_TAU_HOM,
    YAU_MA_TEI,
    SHAM_SHUI_PO,
    NGAU_CHI_WAN,
    NGAU_TAU_KOK,
    SHEK_KIP_MEI,
    SAU_MAU_PING,
    CHUK_YUEN,
    HUNG_HOM,
    MEI_FU,
    LAI_CHI_KOK,
    SO_UK,
    KWUN_TONG,
    DIAMOND_HILL,
    CHEUNG_SHA_WAN,
    MA_TAU_WAI,
    LEI_YUE_MUN,
    WHAMPOA,
    WONG_TAI_SIN,
    SHEUNG_WAN,
    CENTRAL,
    LEI_TUNG,
    NORTH_POINT,
    MID_LEVELS,
    KENNEDY_TOWN,
    TAI_HANG,
    TIN_HAU,
    TAIKOO_SHING,
    SIU_SAI_WAN,
    HENG_FA_CHUEN,
    CHAI_WAN,
    SOUTH_HORIZONS,
    DEEP_WATER_BAY,
    REPULSE_BAY,
    WAN_CHAI,
    FORTRESS_HILL,
    TIN_WAN,
    SHEK_PAI_WAN,
    SHEK_O,
    SHAU_KEI_WAN,
    WAH_FU,
    POK_FU_LAM,
    SAI_WAN_HO,
    SAI_YING_PUN,
    SAI_WAN,
    STANLEY,
    HAPPY_VALLEY,
    ADMIRALTY,
    CAUSEWAY_BAY,
    TELEGRAPH_BAY,
    ABERDEEN,
    QUARRY_BAY,
    AP_LEI_CHAU,
    STAUNTON_VALLEY
};

void splitBy(string src, vector<string>&splitedStr,char sep){
    size_t startpos = 0;
    size_t endpos = src.find(sep,startpos);
    while(endpos!=string::npos){
        splitedStr.push_back(src.substr(startpos,endpos-startpos));
        startpos = endpos+1;
        endpos = src.find('\t',startpos);
    }
    splitedStr.push_back(src.substr(startpos,src.size()-startpos));
}

void addTutor(vector<Tutor> tutors[][30][150][20],const char* line){
    string line_s = line;
    vector<string> data;
    splitBy(line_s,data,'\t');
    //***convert data from string to specific types***//
    //convert sex
    Sex sex = (data[2]=="M")?Sex::M:Sex::F;

    //convert grades
    vector<string>grades;
    splitBy(data[7],grades,',');
    vector<Grade>enum_grades;
    for(int i=0;i<grades.size();++i){
        if(grades[i]=="P1")
            enum_grades.push_back(Grade::P1);
        else if(grades[i]=="P2")
            enum_grades.push_back(Grade::P2);
        else if(grades[i]=="P3")
            enum_grades.push_back(Grade::P3);
        else if(grades[i]=="P4")
            enum_grades.push_back(Grade::P4);
        else if(grades[i]=="P5")
            enum_grades.push_back(Grade::P5);
        else if(grades[i]=="P6")
            enum_grades.push_back(Grade::P6);
        else if(grades[i]=="S1")
            enum_grades.push_back(Grade::S1);
        else if(grades[i]=="S2")
            enum_grades.push_back(Grade::S2);
        else if(grades[i]=="S3")
            enum_grades.push_back(Grade::S3);
        else if(grades[i]=="S4")
            enum_grades.push_back(Grade::S4);
        else if(grades[i]=="S5")
            enum_grades.push_back(Grade::S5);
        else if(grades[i]=="S6")
            enum_grades.push_back(Grade::S6);
    }

    //convert subjects
    vector<string>subjects;
    splitBy(data[8],subjects,',');
    vector<Subject>enum_subjects;
    for(int i=0;i<subjects.size();++i){
        if(subjects[i]=="Chin")
            enum_subjects.push_back(Subject::CHIN);
        else if(subjects[i]=="Eng")
            enum_subjects.push_back(Subject::ENG);
        else if(subjects[i]=="Math_C")
            enum_subjects.push_back(Subject::MATH_C);
        else if(subjects[i]=="Math_E")
            enum_subjects.push_back(Subject::MATH_E);
        else if(subjects[i]=="M1")
            enum_subjects.push_back(Subject::M1);
        else if(subjects[i]=="M2")
            enum_subjects.push_back(Subject::M2);
        else if(subjects[i]=="LS_C")
            enum_subjects.push_back(Subject::LS_C);
        else if(subjects[i]=="LS_E")
            enum_subjects.push_back(Subject::LS_E);
        else if(subjects[i]=="Phys_C")
            enum_subjects.push_back(Subject::PHYS_C);
        else if(subjects[i]=="Phys_E")
            enum_subjects.push_back(Subject::PHYS_E);
        else if(subjects[i]=="Chem_C")
            enum_subjects.push_back(Subject::CHEM_C);
        else if(subjects[i]=="Chem_E")
            enum_subjects.push_back(Subject::CHEM_E);
        else if(subjects[i]=="Bio_C")
            enum_subjects.push_back(Subject::BIO_C);
        else if(subjects[i]=="Bio_E")
            enum_subjects.push_back(Subject::BIO_E);
        else if(subjects[i]=="Geog_C")
            enum_subjects.push_back(Subject::GEOG_C);
        else if(subjects[i]=="Geog_E")
            enum_subjects.push_back(Subject::GEOG_E);
        else if(subjects[i]=="C_History")
            enum_subjects.push_back(Subject::C_HISTORY);
        else if(subjects[i]=="W_History")
            enum_subjects.push_back(Subject::W_HISTORY);
        else if(subjects[i]=="ICT")
            enum_subjects.push_back(Subject::ICT);
        else if(subjects[i]=="ECON")
            enum_subjects.push_back(Subject::ECON);
        else if(subjects[i]=="BAFS")
            enum_subjects.push_back(Subject::BAFS);
        else if(subjects[i]=="Account")
            enum_subjects.push_back(Subject::ACCOUNT);
        else if(subjects[i]=="IS")
            enum_subjects.push_back(Subject::IS);
        else if(subjects[i]=="ChinLit")
            enum_subjects.push_back(Subject::CHINLIT);
        else if(subjects[i]=="EngLit")
            enum_subjects.push_back(Subject::ENGLIT);
        else if(subjects[i]=="VA")
            enum_subjects.push_back(Subject::VA);
    }

     //convert locations
    vector<string>locations;
    splitBy(data[9],locations,',');
    vector<Location>enum_locations;
    for(int i=0;i<locations.size();++i){
        if(locations[i]=="SHEUNG_SHUI")
            enum_locations.push_back(Location::SHEUNG_SHUI);
        else if(locations[i]=="YUEN_LONG")
            enum_locations.push_back(Location::YUEN_LONG);
        else if(locations[i]=="SIU_HONG")
            enum_locations.push_back(Location::SIU_HONG);
        else if(locations[i]=="LAMMA_ISLAND")
            enum_locations.push_back(Location::LAMMA_ISLAND);
        else if(locations[i]=="HANG_HAU")
            enum_locations.push_back(Location::HANG_HAU);
        else if(locations[i]=="PENG_CHAU")
            enum_locations.push_back(Location::PENG_CHAU);
        else if(locations[i]=="TAI_WAI")
            enum_locations.push_back(Location::TAI_WAI);
        else if(locations[i]=="TAI_PO")
            enum_locations.push_back(Location::TAI_PO);
        else if(locations[i]=="LANTAU_ISLAND")
            enum_locations.push_back(Location::LANTAU_ISLAND);
        else if(locations[i]=="TAI_SHUI_HANG")
            enum_locations.push_back(Location::TAI_SHUI_HANG);
        else if(locations[i]=="TAI_WO_HAU")
            enum_locations.push_back(Location::TAI_WO_HAU);
        else if(locations[i]=="TIN_SHUI_WAI")
            enum_locations.push_back(Location::TIN_SHUI_WAI);
        else if(locations[i]=="TAI_WO")
            enum_locations.push_back(Location::TAI_WO);
        else if(locations[i]=="PO_LAM")
            enum_locations.push_back(Location::PO_LAM);
        else if(locations[i]=="TSEUNG_KWAN_O")
            enum_locations.push_back(Location::TSEUNG_KWAN_O);
        else if(locations[i]=="SIU_LEK_YUEN")
            enum_locations.push_back(Location::SIU_LEK_YUEN);
        else if(locations[i]=="TUEN_MUN")
            enum_locations.push_back(Location::TUEN_MUN);
        else if(locations[i]=="LOHAS_PARK")
            enum_locations.push_back(Location::LOHAS_PARK);
        else if(locations[i]=="HENG_ON")
            enum_locations.push_back(Location::HENG_ON);
        else if(locations[i]=="DISCOVERY_BAY")
            enum_locations.push_back(Location::DISCOVERY_BAY);
        else if(locations[i]=="TAK_KU_LING")
            enum_locations.push_back(Location::TAK_KU_LING);
        else if(locations[i]=="LONG_PING")
            enum_locations.push_back(Location::LONG_PING);
        else if(locations[i]=="TUNG_CHUNG")
            enum_locations.push_back(Location::TUNG_CHUNG);
        else if(locations[i]=="LEI_MUK_SHUE")
            enum_locations.push_back(Location::LEI_MUK_SHUE);
        else if(locations[i]=="SUNNY_BAY")
            enum_locations.push_back(Location::SUNNY_BAY);
        else if(locations[i]=="SHA_TIN")
            enum_locations.push_back(Location::SHA_TIN);
        else if(locations[i]=="SHA_TIN_WAI")
            enum_locations.push_back(Location::SHA_TIN_WAI);
        else if(locations[i]=="SHA_TAU_KOK")
            enum_locations.push_back(Location::SHA_TAU_KOK);
        else if(locations[i]=="YAU_TONG")
            enum_locations.push_back(Location::YAU_TONG);
        else if(locations[i]=="HUNG_SHUI_KIU")
            enum_locations.push_back(Location::HUNG_SHUI_KIU);
        else if(locations[i]=="SHAM_TSENG")
            enum_locations.push_back(Location::SHAM_TSENG);
        else if(locations[i]=="CLEAR_WATER_BAY")
            enum_locations.push_back(Location::CLEAR_WATER_BAY);
        else if(locations[i]=="FO_TAN")
            enum_locations.push_back(Location::FO_TAN);
        else if(locations[i]=="WU_KAI_SHA")
            enum_locations.push_back(Location::WU_KAI_SHA);
        else if(locations[i]=="SHEK_LEI")
            enum_locations.push_back(Location::SHEK_LEI);
        else if(locations[i]=="SHEK_YAM")
            enum_locations.push_back(Location::SHEK_YAM);
        else if(locations[i]=="WO_CHE")
            enum_locations.push_back(Location::WO_CHE);
        else if(locations[i]=="CITY_ONE")
            enum_locations.push_back(Location::CITY_ONE);
        else if(locations[i]=="FANLING")
            enum_locations.push_back(Location::FANLING);
        else if(locations[i]=="TSUEN_WAN")
            enum_locations.push_back(Location::TSUEN_WAN);
        else if(locations[i]=="LAI_KING")
            enum_locations.push_back(Location::LAI_KING);
        else if(locations[i]=="KWAI_CHUNG")
            enum_locations.push_back(Location::KWAI_CHUNG);
        else if(locations[i]=="KWAI_SHING")
            enum_locations.push_back(Location::KWAI_SHING);
        else if(locations[i]=="KWAI_HING")
            enum_locations.push_back(Location::KWAI_HING);
        else if(locations[i]=="KWAI_FONG")
            enum_locations.push_back(Location::KWAI_FONG);
        else if(locations[i]=="LAM_TIN")
            enum_locations.push_back(Location::LAM_TIN);
        else if(locations[i]=="SAI_KUNG")
            enum_locations.push_back(Location::SAI_KUNG);
        else if(locations[i]=="TIU_KING_LING")
            enum_locations.push_back(Location::TIU_KING_LING);
        else if(locations[i]=="CHE_KUNG_MIU")
            enum_locations.push_back(Location::CHE_KUNG_MIU);
        else if(locations[i]=="KAM_SHEUNG_ROAD")
            enum_locations.push_back(Location::KAM_SHEUNG_ROAD);
        else if(locations[i]=="CHEUNG_CHAU")
            enum_locations.push_back(Location::CHEUNG_CHAU);
        else if(locations[i]=="TSING_YI")
            enum_locations.push_back(Location::TSING_YI);
        else if(locations[i]=="TSING_LUNG_TAU")
            enum_locations.push_back(Location::TSING_LUNG_TAU);
        else if(locations[i]=="HIN_KENG")
            enum_locations.push_back(Location::HIN_KENG);
        else if(locations[i]=="MA_LIU_SHUI")
            enum_locations.push_back(Location::MA_LIU_SHUI);
        else if(locations[i]=="MA_WAN")
            enum_locations.push_back(Location::MA_WAN);
        else if(locations[i]=="MA_ON_SHAN")
            enum_locations.push_back(Location::MA_ON_SHAN);
        else if(locations[i]=="KOWLOON_CITY")
            enum_locations.push_back(Location::KOWLOON_CITY);
        else if(locations[i]=="KOWLOON_TONG")
            enum_locations.push_back(Location::KOWLOON_TONG);
        else if(locations[i]=="KOWLOON_BAY")
            enum_locations.push_back(Location::KOWLOON_BAY);
        else if(locations[i]=="JORDAN")
            enum_locations.push_back(Location::JORDAN);
        else if(locations[i]=="HO_MAN_TIN")
            enum_locations.push_back(Location::HO_MAN_TIN);
        else if(locations[i]=="NAM_CHEONG")
            enum_locations.push_back(Location::NAM_CHEONG);
        else if(locations[i]=="YAU_YAT_TSUEN")
            enum_locations.push_back(Location::YAU_YAT_TSUEN);
        else if(locations[i]=="KAI_TAK")
            enum_locations.push_back(Location::KAI_TAK);
        else if(locations[i]=="TO_KWA_WAN")
            enum_locations.push_back(Location::TO_KWA_WAN);
        else if(locations[i]=="TAI_WO_PING")
            enum_locations.push_back(Location::TAI_WO_PING);
        else if(locations[i]=="TAI_KOK_TSUI")
            enum_locations.push_back(Location::TAI_KOK_TSUI);
        else if(locations[i]=="PRINCE_EDWARD")
            enum_locations.push_back(Location::PRINCE_EDWARD);
        else if(locations[i]=="OLYMPIC")
            enum_locations.push_back(Location::OLYMPIC);
        else if(locations[i]=="TSIM_SHA_TSUI")
            enum_locations.push_back(Location::TSIM_SHA_TSUI);
        else if(locations[i]=="CHOI_HUNG")
            enum_locations.push_back(Location::CHOI_HUNG);
        else if(locations[i]=="TSZ_WAN_SHAN")
            enum_locations.push_back(Location::TSZ_WAN_SHAN);
        else if(locations[i]=="HAMMER_HILL")
            enum_locations.push_back(Location::HAMMER_HILL);
        else if(locations[i]=="SAN_PO_KONG")
            enum_locations.push_back(Location::SAN_PO_KONG);
        else if(locations[i]=="MONG_KOK")
            enum_locations.push_back(Location::MONG_KOK);
        else if(locations[i]=="AUSTIN")
            enum_locations.push_back(Location::AUSTIN);
        else if(locations[i]=="LOK_FU")
            enum_locations.push_back(Location::LOK_FU);
        else if(locations[i]=="WANG_TAU_HOM")
            enum_locations.push_back(Location::WANG_TAU_HOM);
        else if(locations[i]=="YAU_MA_TEI")
            enum_locations.push_back(Location::YAU_MA_TEI);
        else if(locations[i]=="SHAM_SHUI_PO")
            enum_locations.push_back(Location::SHAM_SHUI_PO);
        else if(locations[i]=="NGAU_CHI_WAN")
            enum_locations.push_back(Location::NGAU_CHI_WAN);
        else if(locations[i]=="NGAU_TAU_KOK")
            enum_locations.push_back(Location::NGAU_TAU_KOK);
        else if(locations[i]=="SHEK_KIP_MEI")
            enum_locations.push_back(Location::SHEK_KIP_MEI);
        else if(locations[i]=="SAU_MAU_PING")
            enum_locations.push_back(Location::SAU_MAU_PING);
        else if(locations[i]=="CHUK_YUEN")
            enum_locations.push_back(Location::CHUK_YUEN);
        else if(locations[i]=="HUNG_HOM")
            enum_locations.push_back(Location::HUNG_HOM);
        else if(locations[i]=="MEI_FU")
            enum_locations.push_back(Location::MEI_FU);
        else if(locations[i]=="LAI_CHI_KOK")
            enum_locations.push_back(Location::LAI_CHI_KOK);
        else if(locations[i]=="SO_UK")
            enum_locations.push_back(Location::SO_UK);
        else if(locations[i]=="KWUN_TONG")
            enum_locations.push_back(Location::KWUN_TONG);
        else if(locations[i]=="DIAMOND_HILL")
            enum_locations.push_back(Location::DIAMOND_HILL);
        else if(locations[i]=="CHEUNG_SHA_WAN")
            enum_locations.push_back(Location::CHEUNG_SHA_WAN);
        else if(locations[i]=="MA_TAU_WAI")
            enum_locations.push_back(Location::MA_TAU_WAI);
        else if(locations[i]=="LEI_YUE_MUN")
            enum_locations.push_back(Location::LEI_YUE_MUN);
        else if(locations[i]=="WHAMPOA")
            enum_locations.push_back(Location::WHAMPOA);
        else if(locations[i]=="WONG_TAI_SIN")
            enum_locations.push_back(Location::WONG_TAI_SIN);
        else if(locations[i]=="SHEUNG_WAN")
            enum_locations.push_back(Location::SHEUNG_WAN);
        else if(locations[i]=="CENTRAL")
            enum_locations.push_back(Location::CENTRAL);
        else if(locations[i]=="LEI_TUNG")
            enum_locations.push_back(Location::LEI_TUNG);
        else if(locations[i]=="NORTH_POINT")
            enum_locations.push_back(Location::NORTH_POINT);
        else if(locations[i]=="MID_LEVELS")
            enum_locations.push_back(Location::MID_LEVELS);
        else if(locations[i]=="KENNEDY_TOWN")
            enum_locations.push_back(Location::KENNEDY_TOWN);
        else if(locations[i]=="TAI_HANG")
            enum_locations.push_back(Location::TAI_HANG);
        else if(locations[i]=="TIN_HAU")
            enum_locations.push_back(Location::TIN_HAU);
        else if(locations[i]=="TAIKOO_SHING")
            enum_locations.push_back(Location::TAIKOO_SHING);
        else if(locations[i]=="SIU_SAI_WAN")
            enum_locations.push_back(Location::SIU_SAI_WAN);
        else if(locations[i]=="HENG_FA_CHUEN")
            enum_locations.push_back(Location::HENG_FA_CHUEN);
        else if(locations[i]=="SOUTH_HORIZONS")
            enum_locations.push_back(Location::SOUTH_HORIZONS);
        else if(locations[i]=="DEEP_WATER_BAY")
            enum_locations.push_back(Location::DEEP_WATER_BAY);
        else if(locations[i]=="REPULSE_BAY")
            enum_locations.push_back(Location::REPULSE_BAY);
        else if(locations[i]=="WAN_CHAI")
            enum_locations.push_back(Location::WAN_CHAI);
        else if(locations[i]=="FORTRESS_HILL")
            enum_locations.push_back(Location::FORTRESS_HILL);
        else if(locations[i]=="TIN_WAN")
            enum_locations.push_back(Location::TIN_WAN);
        else if(locations[i]=="SHEK_PAI_WAN")
            enum_locations.push_back(Location::SHEK_PAI_WAN);
        else if(locations[i]=="SHEK_O")
            enum_locations.push_back(Location::SHEK_O);
        else if(locations[i]=="SHAU_KEI_WAN")
            enum_locations.push_back(Location::SHAU_KEI_WAN);
        else if(locations[i]=="WAH_FU")
            enum_locations.push_back(Location::WAH_FU);
        else if(locations[i]=="POK_FU_LAM")
            enum_locations.push_back(Location::POK_FU_LAM);
        else if(locations[i]=="SAI_WAN_HO")
            enum_locations.push_back(Location::SAI_WAN_HO);
        else if(locations[i]=="SAI_YING_PUN")
            enum_locations.push_back(Location::SAI_YING_PUN);
        else if(locations[i]=="SAI_WAN")
            enum_locations.push_back(Location::SAI_WAN);
        else if(locations[i]=="STANLEY")
            enum_locations.push_back(Location::STANLEY);
        else if(locations[i]=="HAPPY_VALLEY")
            enum_locations.push_back(Location::HAPPY_VALLEY);
        else if(locations[i]=="ADMIRALTY")
            enum_locations.push_back(Location::ADMIRALTY);
        else if(locations[i]=="CAUSEWAY_BAY")
            enum_locations.push_back(Location::CAUSEWAY_BAY);
        else if(locations[i]=="TELEGRAPH_BAY")
            enum_locations.push_back(Location::TELEGRAPH_BAY);
        else if(locations[i]=="ABERDEEN")
            enum_locations.push_back(Location::ABERDEEN);
        else if(locations[i]=="QUARRY_BAY")
            enum_locations.push_back(Location::QUARRY_BAY);
        else if(locations[i]=="AP_LEI_CHAU")
            enum_locations.push_back(Location::AP_LEI_CHAU);
        else if(locations[i]=="STAUNTON_VALLEY")
            enum_locations.push_back(Location::STAUNTON_VALLEY);
    }

    Tutor newPerson(stoi(data[0]),
                    data[1],
                    sex,
                    data[3],
                    data[4],
                    data[5],
                    data[6],
                    enum_grades,
                    enum_subjects,
                    enum_locations,
                    data[10]);
    
    for(int i=0;i<subjects.size();++i){
        for(int j=0;j<locations.size();++j){
            for(int k=0;k<grades.size();++k)
                tutors[(int)sex][(int)enum_subjects[i]][(int)enum_locations[j]][(int)enum_grades[k]].push_back(newPerson);
        }
    }

}

int main(){
    vector<Tutor> tutors[2][30][150][20];
    vector<Student> students[2][30][150][20];
    ifstream ifsTutors("tutor_info.txt");
    ifstream ifsStudents("student_info.txt");

    char* line;
    for(int i=0;!ifsTutors.eof();++i){
        ifsTutors.getline(line,1024,'\n');
        addTutor(tutors,line); 
    }

    return 0;
}