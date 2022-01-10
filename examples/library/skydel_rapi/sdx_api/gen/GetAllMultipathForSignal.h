#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all multipath ID for the specified signal.
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L1P", "L1M", "L2C", "L2P", "L2M", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "SBASL1", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    ///

    class GetAllMultipathForSignal;
    typedef std::shared_ptr<GetAllMultipathForSignal> GetAllMultipathForSignalPtr;
    
    
    class GetAllMultipathForSignal : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllMultipathForSignal();

      GetAllMultipathForSignal(const std::string& signal);
  
      static GetAllMultipathForSignalPtr create(const std::string& signal);
      static GetAllMultipathForSignalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
  }
}

