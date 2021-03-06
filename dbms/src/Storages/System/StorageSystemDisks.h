#pragma once

#include <ext/shared_ptr_helper.h>
#include <Formats/FormatSettings.h>
#include <Storages/IStorage.h>
#include <Storages/MergeTree/MergeTreeData.h>


namespace DB
{

class Context;


/** Implements the system table `disks`, which allows you to get information about all disks.
*/
class StorageSystemDisks : public ext::shared_ptr_helper<StorageSystemDisks>, public IStorage
{
    friend struct ext::shared_ptr_helper<StorageSystemDisks>;
public:
    std::string getName() const override { return "SystemDisks"; }

    BlockInputStreams read(
        const Names & column_names,
        const SelectQueryInfo & query_info,
        const Context & context,
        QueryProcessingStage::Enum processed_stage,
        size_t max_block_size,
        unsigned num_streams) override;

protected:
    StorageSystemDisks(const std::string & name_);
};

}
