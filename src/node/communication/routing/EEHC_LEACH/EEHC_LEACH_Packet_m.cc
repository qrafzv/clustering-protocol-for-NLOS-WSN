//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/routing/EEHC_LEACH/EEHC_LEACH_Packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "EEHC_LEACH_Packet_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("EEHC_LEACH_Packet_Type");
    if (!e) enums.getInstance()->add(e = new cEnum("EEHC_LEACH_Packet_Type"));
    e->insert(EEHC_LEACH_ADV_PACKET, "EEHC_LEACH_ADV_PACKET");
    e->insert(EEHC_LEACH_JOIN_PACKET, "EEHC_LEACH_JOIN_PACKET");
    e->insert(EEHC_LEACH_TDMA_PACKET, "EEHC_LEACH_TDMA_PACKET");
    e->insert(EEHC_LEACH_DATA_PACKET, "EEHC_LEACH_DATA_PACKET");
);

Register_Class(EEHC_LEACH_Packet);

EEHC_LEACH_Packet::EEHC_LEACH_Packet(const char *name, int kind) : ::RoutingPacket(name,kind)
{
    this->EEHC_LEACH_PacketKind_var = 0;
    schedule_arraysize = 0;
    this->schedule_var = 0;
    this->numOfPackets_var = 0;
}

EEHC_LEACH_Packet::EEHC_LEACH_Packet(const EEHC_LEACH_Packet& other) : ::RoutingPacket(other)
{
    schedule_arraysize = 0;
    this->schedule_var = 0;
    copy(other);
}

EEHC_LEACH_Packet::~EEHC_LEACH_Packet()
{
    delete [] schedule_var;
}

EEHC_LEACH_Packet& EEHC_LEACH_Packet::operator=(const EEHC_LEACH_Packet& other)
{
    if (this==&other) return *this;
    ::RoutingPacket::operator=(other);
    copy(other);
    return *this;
}

void EEHC_LEACH_Packet::copy(const EEHC_LEACH_Packet& other)
{
    this->EEHC_LEACH_PacketKind_var = other.EEHC_LEACH_PacketKind_var;
    delete [] this->schedule_var;
    this->schedule_var = (other.schedule_arraysize==0) ? NULL : new int[other.schedule_arraysize];
    schedule_arraysize = other.schedule_arraysize;
    for (unsigned int i=0; i<schedule_arraysize; i++)
        this->schedule_var[i] = other.schedule_var[i];
    this->numOfPackets_var = other.numOfPackets_var;
}

void EEHC_LEACH_Packet::parsimPack(cCommBuffer *b)
{
    ::RoutingPacket::parsimPack(b);
    doPacking(b,this->EEHC_LEACH_PacketKind_var);
    b->pack(schedule_arraysize);
    doPacking(b,this->schedule_var,schedule_arraysize);
    doPacking(b,this->numOfPackets_var);
}

void EEHC_LEACH_Packet::parsimUnpack(cCommBuffer *b)
{
    ::RoutingPacket::parsimUnpack(b);
    doUnpacking(b,this->EEHC_LEACH_PacketKind_var);
    delete [] this->schedule_var;
    b->unpack(schedule_arraysize);
    if (schedule_arraysize==0) {
        this->schedule_var = 0;
    } else {
        this->schedule_var = new int[schedule_arraysize];
        doUnpacking(b,this->schedule_var,schedule_arraysize);
    }
    doUnpacking(b,this->numOfPackets_var);
}

int EEHC_LEACH_Packet::getEEHC_LEACH_PacketKind() const
{
    return EEHC_LEACH_PacketKind_var;
}

void EEHC_LEACH_Packet::setEEHC_LEACH_PacketKind(int EEHC_LEACH_PacketKind)
{
    this->EEHC_LEACH_PacketKind_var = EEHC_LEACH_PacketKind;
}

void EEHC_LEACH_Packet::setScheduleArraySize(unsigned int size)
{
    int *schedule_var2 = (size==0) ? NULL : new int[size];
    unsigned int sz = schedule_arraysize < size ? schedule_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        schedule_var2[i] = this->schedule_var[i];
    for (unsigned int i=sz; i<size; i++)
        schedule_var2[i] = 0;
    schedule_arraysize = size;
    delete [] this->schedule_var;
    this->schedule_var = schedule_var2;
}

unsigned int EEHC_LEACH_Packet::getScheduleArraySize() const
{
    return schedule_arraysize;
}

int EEHC_LEACH_Packet::getSchedule(unsigned int k) const
{
    if (k>=schedule_arraysize) throw cRuntimeError("Array of size %d indexed by %d", schedule_arraysize, k);
    return schedule_var[k];
}

void EEHC_LEACH_Packet::setSchedule(unsigned int k, int schedule)
{
    if (k>=schedule_arraysize) throw cRuntimeError("Array of size %d indexed by %d", schedule_arraysize, k);
    this->schedule_var[k] = schedule;
}

int EEHC_LEACH_Packet::getNumOfPackets() const
{
    return numOfPackets_var;
}

void EEHC_LEACH_Packet::setNumOfPackets(int numOfPackets)
{
    this->numOfPackets_var = numOfPackets;
}

class EEHC_LEACH_PacketDescriptor : public cClassDescriptor
{
  public:
    EEHC_LEACH_PacketDescriptor();
    virtual ~EEHC_LEACH_PacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(EEHC_LEACH_PacketDescriptor);

EEHC_LEACH_PacketDescriptor::EEHC_LEACH_PacketDescriptor() : cClassDescriptor("EEHC_LEACH_Packet", "RoutingPacket")
{
}

EEHC_LEACH_PacketDescriptor::~EEHC_LEACH_PacketDescriptor()
{
}

bool EEHC_LEACH_PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<EEHC_LEACH_Packet *>(obj)!=NULL;
}

const char *EEHC_LEACH_PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int EEHC_LEACH_PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int EEHC_LEACH_PacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *EEHC_LEACH_PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "EEHC_LEACH_PacketKind",
        "schedule",
        "numOfPackets",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int EEHC_LEACH_PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='E' && strcmp(fieldName, "EEHC_LEACH_PacketKind")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "schedule")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "numOfPackets")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *EEHC_LEACH_PacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *EEHC_LEACH_PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "EEHC_LEACH_Packet_Type";
            return NULL;
        default: return NULL;
    }
}

int EEHC_LEACH_PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    EEHC_LEACH_Packet *pp = (EEHC_LEACH_Packet *)object; (void)pp;
    switch (field) {
        case 1: return pp->getScheduleArraySize();
        default: return 0;
    }
}

std::string EEHC_LEACH_PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    EEHC_LEACH_Packet *pp = (EEHC_LEACH_Packet *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getEEHC_LEACH_PacketKind());
        case 1: return long2string(pp->getSchedule(i));
        case 2: return long2string(pp->getNumOfPackets());
        default: return "";
    }
}

bool EEHC_LEACH_PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    EEHC_LEACH_Packet *pp = (EEHC_LEACH_Packet *)object; (void)pp;
    switch (field) {
        case 0: pp->setEEHC_LEACH_PacketKind(string2long(value)); return true;
        case 1: pp->setSchedule(i,string2long(value)); return true;
        case 2: pp->setNumOfPackets(string2long(value)); return true;
        default: return false;
    }
}

const char *EEHC_LEACH_PacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *EEHC_LEACH_PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    EEHC_LEACH_Packet *pp = (EEHC_LEACH_Packet *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


