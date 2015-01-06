#ifndef BERT_QSORTEDSET_H
#define BERT_QSORTEDSET_H

#include "QString.h"
#include "util.h"
#include <map>
#include <set>
#include <vector>

#if defined(__APPLE__)
#include <unordered_map>

#else
#include <tr1/unordered_map>

#endif

class QSortedSet
{
public:
    typedef std::set<QString> Members;
    typedef std::map<long, Members>  Score2Members;
#if defined(__APPLE__)
    typedef std::unordered_map<QString, long,
            my_hash,
            std::equal_to<QString> >   Member2Score;

#else
    typedef std::tr1::unordered_map<QString, long,
            my_hash,
            std::equal_to<QString> >   Member2Score;

#endif

    Member2Score::iterator FindMember(const QString& member);
    Member2Score::const_iterator end() const {  return m_members.end(); };
    Member2Score::iterator end() {  return m_members.end(); };
    void    AddMember   (const QString& member, long score);
    long    UpdateMember(const Member2Score::iterator& itMem, long delta);

    int     Rank        (const QString& member) const;// 0-based
    int     RevRank     (const QString& member) const;// 0-based
    bool    DelMember   (const QString& member);
    std::pair<QString, long>
        GetMemberByRank(std::size_t rank) const;
    
    std::vector<std::pair<QString, long> > RangeByRank(long start, long end) const;

    std::vector<std::pair<QString, long> >
        RangeByScore(long minScore, long maxScore);
    std::size_t Size    ()  const;

private:
    Score2Members   m_scores;
    Member2Score    m_members;
};

#endif 
