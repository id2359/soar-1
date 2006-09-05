#ifdef HAVE_CONFIG_H
#include "config.h"
#endif // HAVE_CONFIG_H
#include "portability.h"

/*************************************************************************
 * PLEASE SEE THE FILE "COPYING" (INCLUDED WITH THIS SOFTWARE PACKAGE)
 * FOR LICENSE AND COPYRIGHT INFORMATION. 
 *************************************************************************/

/********************************************************************
* @file gski_conditionset.cpp
*********************************************************************
* created:	   6/27/2002   10:44
*
* purpose: 
*********************************************************************/
#include "gSKI_ConditionSet.h"
#include "gSKI_Condition.h"
#include "gSKI_Test.h"
#include "gSKI_Iterator.h"
#include "gSKI_TestSet.h"
#include "gSKI_Test.h"

#include <vector>
#include <iostream>

#include "gdatastructs.h"
#include "production.h"

namespace gSKI 
{
   /*
   ==================================
  ____                _ _ _   _             ____       _
 / ___|___  _ __   __| (_) |_(_) ___  _ __ / ___|  ___| |_
| |   / _ \| '_ \ / _` | | __| |/ _ \| '_ \\___ \ / _ \ __|
| |__| (_) | | | | (_| | | |_| | (_) | | | |___) |  __/ |_
 \____\___/|_| |_|\__,_|_|\__|_|\___/|_| |_|____/ \___|\__|
   ==================================
   */
   ConditionSet::ConditionSet(agent* a) : m_agent(a)
   {

   }

   /*
   ===============================
 /\/|___                _ _ _   _             ____       _
|/\/ ___|___  _ __   __| (_) |_(_) ___  _ __ / ___|  ___| |_
  | |   / _ \| '_ \ / _` | | __| |/ _ \| '_ \\___ \ / _ \ __|
  | |__| (_) | | | | (_| | | |_| | (_) | | | |___) |  __/ |_
   \____\___/|_| |_|\__,_|_|\__|_|\___/|_| |_|____/ \___|\__|
   ===============================
   */
   ConditionSet::~ConditionSet()
   {
      std::vector<Condition*>::iterator condIt = m_conditions.begin();
      for( ; condIt != m_conditions.end(); ++condIt)
      {
         Condition* c = *condIt;
         delete(c);
      }
   }

   /*
   ===============================
  ____      _    ____                _ _ _   _
 / ___| ___| |_ / ___|___  _ __   __| (_) |_(_) ___  _ __  ___
| |  _ / _ \ __| |   / _ \| '_ \ / _` | | __| |/ _ \| '_ \/ __|
| |_| |  __/ |_| |__| (_) | | | | (_| | | |_| | (_) | | | \__ \
 \____|\___|\__|\____\___/|_| |_|\__,_|_|\__|_|\___/|_| |_|___/
   ===============================
   */

   tIConditionIterator* ConditionSet::GetConditions(Error *pErr) 
   {
      //return new tConditionIterator(m_conditions);
      return new Iterator<Condition *, tConditionVec>(m_conditions);
   }

   /*
   ===============================
  ____      _   _   _                  ____                _ _ _   _
 / ___| ___| |_| \ | |_   _ _ __ ___  / ___|___  _ __   __| (_) |_(_) ___  _ __  ___
| |  _ / _ \ __|  \| | | | | '_ ` _ \| |   / _ \| '_ \ / _` | | __| |/ _ \| '_ \/ __|
| |_| |  __/ |_| |\  | |_| | | | | | | |__| (_) | | | | (_| | | |_| | (_) | | | \__ \
 \____|\___|\__|_| \_|\__,_|_| |_| |_|\____\___/|_| |_|\__,_|_|\__|_|\___/|_| |_|___/
   ===============================
   */

   unsigned int ConditionSet::GetNumConditions(Error *pErr)const
   {
      return 0;
   }

   /*
   ===============================
  ____      _    ____                _ _ _   _             ____       _
 / ___| ___| |_ / ___|___  _ __   __| (_) |_(_) ___  _ __ / ___|  ___| |_ ___
| |  _ / _ \ __| |   / _ \| '_ \ / _` | | __| |/ _ \| '_ \\___ \ / _ \ __/ __|
| |_| |  __/ |_| |__| (_) | | | | (_| | | |_| | (_) | | | |___) |  __/ |_\__ \
 \____|\___|\__|\____\___/|_| |_|\__,_|_|\__|_|\___/|_| |_|____/ \___|\__|___/
   ===============================
   */

   tIConditionSetIterator *ConditionSet::GetConditionSets(Error *pErr) const
   {
      //return new Iterator<tConditionSet::V *, tConditionSet::t>(m_conditionSets);
      return new tConditionSetIter(m_conditionSets);
   }

   /*
   ===============================
  ____      _   _   _                  ____                _ _ _   _
 / ___| ___| |_| \ | |_   _ _ __ ___  / ___|___  _ __   __| (_) |_(_) ___  _ __
| |  _ / _ \ __|  \| | | | | '_ ` _ \| |   / _ \| '_ \ / _` | | __| |/ _ \| '_ \
| |_| |  __/ |_| |\  | |_| | | | | | | |__| (_) | | | | (_| | | |_| | (_) | | | |
 \____|\___|\__|_| \_|\__,_|_| |_| |_|\____\___/|_| |_|\__,_|_|\__|_|\___/|_| |_|
/ ___|  ___| |_ ___
\___ \ / _ \ __/ __|
 ___) |  __/ |_\__ \
|____/ \___|\__|___/
   ===============================
   */

   unsigned int ConditionSet::GetNumConditionSets(Error *pErr) const
   {
      return static_cast<unsigned int>(m_conditionSets.size());
   }

   /*
   ===============================
 ___     _   _                  _           _
|_ _|___| \ | | ___  __ _  __ _| |_ ___  __| |
 | |/ __|  \| |/ _ \/ _` |/ _` | __/ _ \/ _` |
 | |\__ \ |\  |  __/ (_| | (_| | ||  __/ (_| |
|___|___/_| \_|\___|\__, |\__,_|\__\___|\__,_|
                    |___/
   ===============================
   */

   bool ConditionSet::IsNegated(Error *pErr) const
   {
      return true;
   }

   /*
   ==================================
    _       _     _  ____                _ _ _   _
   / \   __| | __| |/ ___|___  _ __   __| (_) |_(_) ___  _ __
  / _ \ / _` |/ _` | |   / _ \| '_ \ / _` | | __| |/ _ \| '_ \
 / ___ \ (_| | (_| | |__| (_) | | | | (_| | | |_| | (_) | | | |
/_/   \_\__,_|\__,_|\____\___/|_| |_|\__,_|_|\__|_|\___/|_| |_|
   ==================================
   */
   void ConditionSet::AddCondition(condition *cond)
   {
      m_conditions.push_back(new Condition(cond, m_agent));
   }

   /*
   ==================================
    _       _     _  ____                _ _ _   _             ____       _
   / \   __| | __| |/ ___|___  _ __   __| (_) |_(_) ___  _ __ / ___|  ___| |_
  / _ \ / _` |/ _` | |   / _ \| '_ \ / _` | | __| |/ _ \| '_ \\___ \ / _ \ __|
 / ___ \ (_| | (_| | |__| (_) | | | | (_| | | |_| | (_) | | | |___) |  __/ |_
/_/   \_\__,_|\__,_|\____\___/|_| |_|\__,_|_|\__|_|\___/|_| |_|____/ \___|\__|
   ==================================
   */
   ConditionSet* ConditionSet::AddConditionSet()
   {
      ConditionSet* newConditionSet = new ConditionSet(m_agent);
      m_conditionSets.push_back(newConditionSet);
      return newConditionSet;
   }


}
