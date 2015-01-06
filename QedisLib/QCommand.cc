#include "QCommand.h"

using std::size_t;

const QCommandInfo QCommandTable::s_info[] =
{
    // key
    {"type",        QAttr_read,                2,  &type},
    {"exists",      QAttr_read,                2,  &exists},
    {"del",         QAttr_write,              -2,  &del},
    {"expire",      QAttr_write,               3,  &expire},
    {"ttl",         QAttr_read,                2,  &ttl},
    {"pexpire",     QAttr_write,               3,  &pexpire},
    {"pttl",        QAttr_read,                2,  &pttl},
    {"expireat",    QAttr_write,               3,  &expireat},
    {"pexpireat",   QAttr_write,               3,  &pexpireat},
    {"persist",     QAttr_read,                2,  &persist},
    {"move",        QAttr_write,               3,  &move},
    {"keys",        QAttr_read,                2,  &keys},
    {"randomkey",   QAttr_read,                1,  &randomkey},

    // server
    {"select",      QAttr_read,                2,  &select},
    {"dbsize",      QAttr_read,                1,  &dbsize},
    
    // string
    {"strlen",      QAttr_read,                2,  &strlen},
    {"set",         QAttr_write,               3,  &set},
    {"mset",        QAttr_write,              -3,  &mset},
    {"msetnx",      QAttr_write,              -3,  &msetnx},
    {"setnx",       QAttr_write,               3,  &setnx},
    {"setex",       QAttr_write,               4,  &setex},
    {"get",         QAttr_read,                2,  &get},
    {"getset",      QAttr_write,               3,  &getset},
    {"mget",        QAttr_read,               -2,  &mget},
    {"append",      QAttr_write,               3,  &append},
    {"bitcount",    QAttr_read,               -2,  &bitcount},
    {"getbit",      QAttr_read,                3,  &getbit},
    {"setbit",      QAttr_write,               4,  &setbit},
    {"incr",        QAttr_write,               2,  &incr},
    {"decr",        QAttr_write,               2,  &decr},
    {"incrby",      QAttr_write,               3,  &incrby},
    {"decrby",      QAttr_write,               3,  &decrby},
    {"getrange",    QAttr_read,                4,  &getrange},
    {"setrange",    QAttr_write,               4,  &setrange},

    // list
    {"lpush",       QAttr_write,              -3,  &lpush},
    {"rpush",       QAttr_write,              -3,  &rpush},
    {"lpushx",      QAttr_write,              -3,  &lpushx},
    {"rpushx",      QAttr_write,              -3,  &rpushx},
    {"lpop",        QAttr_write,               2,  &lpop},
    {"rpop",        QAttr_write,               2,  &rpop},
    {"lindex",      QAttr_read,                3,  &lindex},
    {"llen",        QAttr_read,                2,  &llen},
    {"lset",        QAttr_write,               4,  &lset},
    {"ltrim",       QAttr_write,               4,  &ltrim},
    {"lrange",      QAttr_write,               4,  &lrange},
    {"linsert",     QAttr_write,               5,  &linsert},
    {"lrem",        QAttr_write,               4,  &lrem},
    {"rpoplpush",   QAttr_write,               3,  &rpoplpush},
    
    
    // hash
    {"hget",        QAttr_read,                3,  &hget},
    {"hgetall",     QAttr_read,                2,  &hgetall},
    {"hmget",       QAttr_read,               -3,  &hmget},
    {"hset",        QAttr_write,               4,  &hset},
    {"hsetnx",      QAttr_write,               4,  &hsetnx},
    {"hmset",       QAttr_write,              -4,  &hmset},
    {"hlen",        QAttr_read,                2,  &hlen},
    {"hexists",     QAttr_read,                3,  &hexists},
    {"hkeys",       QAttr_read,                2,  &hkeys},
    {"hvals",       QAttr_read,                2,  &hvals},
    {"hdel",        QAttr_write,              -3,  &hdel},
    {"hincrby",     QAttr_write,               4,  &hincrby},
    {"hincrbyfloat",QAttr_write,               4,  &hincrbyfloat},

    // set
    {"sadd",        QAttr_write,              -3,  &sadd},
    {"scard",       QAttr_read,                2,  &scard},
    {"sismember",   QAttr_read,                3,  &sismember},
    {"srem",        QAttr_write,              -3,  &srem},
    {"smembers",    QAttr_read,                2,  &smembers},
    {"sdiff",       QAttr_read,               -2,  &sdiff},
    {"sdiffstore",  QAttr_write,              -3,  &sdiffstore},
    {"sinter",      QAttr_read,               -2,  &sinter},
    {"sinterstore", QAttr_write,              -3,  &sinterstore},
    {"sunion",      QAttr_read,               -2,  &sunion},
    {"sunionstore", QAttr_write,              -3,  &sunionstore},
    {"smove",       QAttr_write,               4,  &smove},
    {"spop",        QAttr_write,               2,  &spop},
    {"srandmember", QAttr_write,               2,  &srandmember},

    //
    {"zadd",        QAttr_write,              -4,  &zadd},
    {"zcard",       QAttr_read,                2,  &zcard},
    {"zrank",       QAttr_read,                3,  &zrank},
    {"zrevrank",    QAttr_read,                3,  &zrevrank},
    {"zrem",        QAttr_write,              -3,  &zrem},
    {"zincrby",     QAttr_write,               4,  &zincrby},
    {"zscore",      QAttr_read,                3,  &zscore},
    {"zrange",      QAttr_read,               -4,  &zrange},
    {"zrevrange",   QAttr_read,               -4,  &zrevrange},
    {"zrangebyscore",   QAttr_read,           -4,  &zrangebyscore},
    {"zrevrangebyscore",QAttr_read,           -4,  &zrevrangebyscore},
    {"zremrangebyrank", QAttr_write,           4,  &zremrangebyrank},
    {"zremrangebyscore",QAttr_write,           4,  &zremrangebyscore},

    // pubsub
    {"subscribe",   QAttr_read,               -2,  &subscribe},
    {"unsubscribe", QAttr_read,               -1,  &unsubscribe},
    {"publish",     QAttr_read,                3,  &publish},
    {"psubscribe",  QAttr_read,               -2,  &psubscribe},
    {"punsubscribe",QAttr_read,               -1,  &punsubscribe},
    {"pubsub",      QAttr_read,               -2,  &pubsub},
    
    
    // multi
    {"watch",       QAttr_read,               -2,  &watch},
    {"unwatch",     QAttr_read,                1,  &unwatch},
    {"multi",       QAttr_read,                1,  &multi},
    {"exec",        QAttr_read,                1,  &exec},
    {"discard",     QAttr_read,                1,  &discard},
};


std::map<QString, const QCommandInfo* >  QCommandTable::s_handlers;

QCommandTable::QCommandTable()
{
    Init();
}

void QCommandTable::Init()
{
    for (size_t i = 0; i < sizeof s_info / sizeof s_info[0]; ++ i)
    {
        const QCommandInfo& info = s_info[i];
        s_handlers[info.cmd] = &info;
    }
}

const QCommandInfo* QCommandTable::GetCommandInfo(const QString& cmd)
{
    std::map<QString, const QCommandInfo* >::const_iterator it(s_handlers.find(cmd));
    if (it != s_handlers.end())
    {
        return it->second;
    }
    
    return  0;
}

QError QCommandTable::ExecuteCmd(const std::vector<QString>& params, const QCommandInfo* info, UnboundedBuffer& reply)
{
    if (params.empty())
    {
        ReplyError(QError_param, reply);
        return   QError_param;
    }

    if (!info)
    {
        ReplyError(QError_unknowCmd, reply);
        return QError_unknowCmd;
    }
    
    if (!info->CheckParamsCount(static_cast<int>(params.size())))
    {
        ReplyError(QError_param, reply);
        return   QError_param;
    }

    return info->handler(params, reply);
}

QError QCommandTable::ExecuteCmd(const std::vector<QString>& params, UnboundedBuffer& reply)
{
    if (params.empty())
    {
        ReplyError(QError_param, reply);
        return   QError_param;
    }
    
    std::map<QString, const QCommandInfo* >::const_iterator it(s_handlers.find(params[0]));
    if (it == s_handlers.end())
    {
        ReplyError(QError_unknowCmd, reply);
        return QError_unknowCmd;
    }
    
    const QCommandInfo* info = it->second;
    if (!info->CheckParamsCount(static_cast<int>(params.size())))
    {
        ReplyError(QError_param, reply);
        return   QError_param;
    }
    
    return info->handler(params, reply);
}

    
bool QCommandInfo::CheckParamsCount(int nParams) const
{
    if (params > 0)
        return params == nParams;
    else
        return nParams + params >= 0;
}
