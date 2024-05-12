// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/mission_raw/mission_raw.proto)

#include "mission_raw/mission_raw.grpc.pb.h"
#include "plugins/mission_raw/mission_raw.h"

#include "mavsdk.h"

#include "lazy_plugin.h"

#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <mutex>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace mavsdk_server {

template<typename MissionRaw = MissionRaw, typename LazyPlugin = LazyPlugin<MissionRaw>>

class MissionRawServiceImpl final : public rpc::mission_raw::MissionRawService::Service {
public:
    MissionRawServiceImpl(LazyPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}

    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::MissionRaw::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_mission_raw_result = new rpc::mission_raw::MissionRawResult();
        rpc_mission_raw_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_mission_raw_result->set_result_str(ss.str());

        response->set_allocated_mission_raw_result(rpc_mission_raw_result);
    }

    static std::unique_ptr<rpc::mission_raw::MissionProgress>
    translateToRpcMissionProgress(const mavsdk::MissionRaw::MissionProgress& mission_progress)
    {
        auto rpc_obj = std::make_unique<rpc::mission_raw::MissionProgress>();

        rpc_obj->set_current(mission_progress.current);

        rpc_obj->set_total(mission_progress.total);

        return rpc_obj;
    }

    static mavsdk::MissionRaw::MissionProgress
    translateFromRpcMissionProgress(const rpc::mission_raw::MissionProgress& mission_progress)
    {
        mavsdk::MissionRaw::MissionProgress obj;

        obj.current = mission_progress.current();

        obj.total = mission_progress.total();

        return obj;
    }

    static std::unique_ptr<rpc::mission_raw::MissionItem>
    translateToRpcMissionItem(const mavsdk::MissionRaw::MissionItem& mission_item)
    {
        auto rpc_obj = std::make_unique<rpc::mission_raw::MissionItem>();

        rpc_obj->set_seq(mission_item.seq);

        rpc_obj->set_frame(mission_item.frame);

        rpc_obj->set_command(mission_item.command);

        rpc_obj->set_current(mission_item.current);

        rpc_obj->set_autocontinue(mission_item.autocontinue);

        rpc_obj->set_param1(mission_item.param1);

        rpc_obj->set_param2(mission_item.param2);

        rpc_obj->set_param3(mission_item.param3);

        rpc_obj->set_param4(mission_item.param4);

        rpc_obj->set_x(mission_item.x);

        rpc_obj->set_y(mission_item.y);

        rpc_obj->set_z(mission_item.z);

        rpc_obj->set_mission_type(mission_item.mission_type);

        return rpc_obj;
    }

    static mavsdk::MissionRaw::MissionItem
    translateFromRpcMissionItem(const rpc::mission_raw::MissionItem& mission_item)
    {
        mavsdk::MissionRaw::MissionItem obj;

        obj.seq = mission_item.seq();

        obj.frame = mission_item.frame();

        obj.command = mission_item.command();

        obj.current = mission_item.current();

        obj.autocontinue = mission_item.autocontinue();

        obj.param1 = mission_item.param1();

        obj.param2 = mission_item.param2();

        obj.param3 = mission_item.param3();

        obj.param4 = mission_item.param4();

        obj.x = mission_item.x();

        obj.y = mission_item.y();

        obj.z = mission_item.z();

        obj.mission_type = mission_item.mission_type();

        return obj;
    }

    static std::unique_ptr<rpc::mission_raw::MissionImportData> translateToRpcMissionImportData(
        const mavsdk::MissionRaw::MissionImportData& mission_import_data)
    {
        auto rpc_obj = std::make_unique<rpc::mission_raw::MissionImportData>();

        for (const auto& elem : mission_import_data.mission_items) {
            auto* ptr = rpc_obj->add_mission_items();
            ptr->CopyFrom(*translateToRpcMissionItem(elem).release());
        }

        for (const auto& elem : mission_import_data.geofence_items) {
            auto* ptr = rpc_obj->add_geofence_items();
            ptr->CopyFrom(*translateToRpcMissionItem(elem).release());
        }

        for (const auto& elem : mission_import_data.rally_items) {
            auto* ptr = rpc_obj->add_rally_items();
            ptr->CopyFrom(*translateToRpcMissionItem(elem).release());
        }

        return rpc_obj;
    }

    static mavsdk::MissionRaw::MissionImportData translateFromRpcMissionImportData(
        const rpc::mission_raw::MissionImportData& mission_import_data)
    {
        mavsdk::MissionRaw::MissionImportData obj;

        for (const auto& elem : mission_import_data.mission_items()) {
            obj.mission_items.push_back(translateFromRpcMissionItem(
                static_cast<mavsdk::rpc::mission_raw::MissionItem>(elem)));
        }

        for (const auto& elem : mission_import_data.geofence_items()) {
            obj.geofence_items.push_back(translateFromRpcMissionItem(
                static_cast<mavsdk::rpc::mission_raw::MissionItem>(elem)));
        }

        for (const auto& elem : mission_import_data.rally_items()) {
            obj.rally_items.push_back(translateFromRpcMissionItem(
                static_cast<mavsdk::rpc::mission_raw::MissionItem>(elem)));
        }

        return obj;
    }

    static rpc::mission_raw::MissionRawResult::Result
    translateToRpcResult(const mavsdk::MissionRaw::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::MissionRaw::Result::Unknown:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_UNKNOWN;
            case mavsdk::MissionRaw::Result::Success:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_SUCCESS;
            case mavsdk::MissionRaw::Result::Error:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_ERROR;
            case mavsdk::MissionRaw::Result::TooManyMissionItems:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_TOO_MANY_MISSION_ITEMS;
            case mavsdk::MissionRaw::Result::Busy:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_BUSY;
            case mavsdk::MissionRaw::Result::Timeout:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_TIMEOUT;
            case mavsdk::MissionRaw::Result::InvalidArgument:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_INVALID_ARGUMENT;
            case mavsdk::MissionRaw::Result::Unsupported:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_UNSUPPORTED;
            case mavsdk::MissionRaw::Result::NoMissionAvailable:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_NO_MISSION_AVAILABLE;
            case mavsdk::MissionRaw::Result::TransferCancelled:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_TRANSFER_CANCELLED;
            case mavsdk::MissionRaw::Result::FailedToOpenQgcPlan:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_FAILED_TO_OPEN_QGC_PLAN;
            case mavsdk::MissionRaw::Result::FailedToParseQgcPlan:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_FAILED_TO_PARSE_QGC_PLAN;
            case mavsdk::MissionRaw::Result::NoSystem:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_NO_SYSTEM;
            case mavsdk::MissionRaw::Result::Denied:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_DENIED;
            case mavsdk::MissionRaw::Result::MissionTypeNotConsistent:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_MISSION_TYPE_NOT_CONSISTENT;
            case mavsdk::MissionRaw::Result::InvalidSequence:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_INVALID_SEQUENCE;
            case mavsdk::MissionRaw::Result::CurrentInvalid:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_CURRENT_INVALID;
            case mavsdk::MissionRaw::Result::ProtocolError:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_PROTOCOL_ERROR;
            case mavsdk::MissionRaw::Result::IntMessagesNotSupported:
                return rpc::mission_raw::MissionRawResult_Result_RESULT_INT_MESSAGES_NOT_SUPPORTED;
        }
    }

    static mavsdk::MissionRaw::Result
    translateFromRpcResult(const rpc::mission_raw::MissionRawResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::mission_raw::MissionRawResult_Result_RESULT_UNKNOWN:
                return mavsdk::MissionRaw::Result::Unknown;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_SUCCESS:
                return mavsdk::MissionRaw::Result::Success;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_ERROR:
                return mavsdk::MissionRaw::Result::Error;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_TOO_MANY_MISSION_ITEMS:
                return mavsdk::MissionRaw::Result::TooManyMissionItems;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_BUSY:
                return mavsdk::MissionRaw::Result::Busy;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_TIMEOUT:
                return mavsdk::MissionRaw::Result::Timeout;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_INVALID_ARGUMENT:
                return mavsdk::MissionRaw::Result::InvalidArgument;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_UNSUPPORTED:
                return mavsdk::MissionRaw::Result::Unsupported;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_NO_MISSION_AVAILABLE:
                return mavsdk::MissionRaw::Result::NoMissionAvailable;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_TRANSFER_CANCELLED:
                return mavsdk::MissionRaw::Result::TransferCancelled;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_FAILED_TO_OPEN_QGC_PLAN:
                return mavsdk::MissionRaw::Result::FailedToOpenQgcPlan;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_FAILED_TO_PARSE_QGC_PLAN:
                return mavsdk::MissionRaw::Result::FailedToParseQgcPlan;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_NO_SYSTEM:
                return mavsdk::MissionRaw::Result::NoSystem;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_DENIED:
                return mavsdk::MissionRaw::Result::Denied;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_MISSION_TYPE_NOT_CONSISTENT:
                return mavsdk::MissionRaw::Result::MissionTypeNotConsistent;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_INVALID_SEQUENCE:
                return mavsdk::MissionRaw::Result::InvalidSequence;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_CURRENT_INVALID:
                return mavsdk::MissionRaw::Result::CurrentInvalid;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_PROTOCOL_ERROR:
                return mavsdk::MissionRaw::Result::ProtocolError;
            case rpc::mission_raw::MissionRawResult_Result_RESULT_INT_MESSAGES_NOT_SUPPORTED:
                return mavsdk::MissionRaw::Result::IntMessagesNotSupported;
        }
    }

    grpc::Status UploadMission(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::UploadMissionRequest* request,
        rpc::mission_raw::UploadMissionResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "UploadMission sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        std::vector<mavsdk::MissionRaw::MissionItem> mission_items_vec;
        for (const auto& elem : request->mission_items()) {
            mission_items_vec.push_back(translateFromRpcMissionItem(elem));
        }

        auto result = _lazy_plugin.maybe_plugin()->upload_mission(mission_items_vec);

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status UploadGeofence(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::UploadGeofenceRequest* request,
        rpc::mission_raw::UploadGeofenceResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "UploadGeofence sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        std::vector<mavsdk::MissionRaw::MissionItem> mission_items_vec;
        for (const auto& elem : request->mission_items()) {
            mission_items_vec.push_back(translateFromRpcMissionItem(elem));
        }

        auto result = _lazy_plugin.maybe_plugin()->upload_geofence(mission_items_vec);

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status UploadRallyPoints(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::UploadRallyPointsRequest* request,
        rpc::mission_raw::UploadRallyPointsResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "UploadRallyPoints sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        std::vector<mavsdk::MissionRaw::MissionItem> mission_items_vec;
        for (const auto& elem : request->mission_items()) {
            mission_items_vec.push_back(translateFromRpcMissionItem(elem));
        }

        auto result = _lazy_plugin.maybe_plugin()->upload_rally_points(mission_items_vec);

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status CancelMissionUpload(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::CancelMissionUploadRequest* /* request */,
        rpc::mission_raw::CancelMissionUploadResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->cancel_mission_upload();

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status DownloadMission(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::DownloadMissionRequest* /* request */,
        rpc::mission_raw::DownloadMissionResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->download_mission();

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);

            for (auto elem : result.second) {
                auto* ptr = response->add_mission_items();
                ptr->CopyFrom(*translateToRpcMissionItem(elem).release());
            }
        }

        return grpc::Status::OK;
    }

    grpc::Status CancelMissionDownload(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::CancelMissionDownloadRequest* /* request */,
        rpc::mission_raw::CancelMissionDownloadResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->cancel_mission_download();

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status StartMission(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::StartMissionRequest* /* request */,
        rpc::mission_raw::StartMissionResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->start_mission();

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status PauseMission(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::PauseMissionRequest* /* request */,
        rpc::mission_raw::PauseMissionResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->pause_mission();

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status ClearMission(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::ClearMissionRequest* /* request */,
        rpc::mission_raw::ClearMissionResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->clear_mission();

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status SetCurrentMissionItem(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::SetCurrentMissionItemRequest* request,
        rpc::mission_raw::SetCurrentMissionItemResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "SetCurrentMissionItem sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->set_current_mission_item(request->index());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status SubscribeMissionProgress(
        grpc::ServerContext* /* context */,
        const mavsdk::rpc::mission_raw::SubscribeMissionProgressRequest* /* request */,
        grpc::ServerWriter<rpc::mission_raw::MissionProgressResponse>* writer) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            return grpc::Status::OK;
        }

        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);
        auto subscribe_mutex = std::make_shared<std::mutex>();

        const mavsdk::MissionRaw::MissionProgressHandle handle =
            _lazy_plugin.maybe_plugin()->subscribe_mission_progress(
                [this, &writer, &stream_closed_promise, is_finished, subscribe_mutex, &handle](
                    const mavsdk::MissionRaw::MissionProgress mission_progress) {
                    rpc::mission_raw::MissionProgressResponse rpc_response;

                    rpc_response.set_allocated_mission_progress(
                        translateToRpcMissionProgress(mission_progress).release());

                    std::unique_lock<std::mutex> lock(*subscribe_mutex);
                    if (!*is_finished && !writer->Write(rpc_response)) {
                        _lazy_plugin.maybe_plugin()->unsubscribe_mission_progress(handle);

                        *is_finished = true;
                        unregister_stream_stop_promise(stream_closed_promise);
                        stream_closed_promise->set_value();
                    }
                });

        stream_closed_future.wait();
        std::unique_lock<std::mutex> lock(*subscribe_mutex);
        *is_finished = true;

        return grpc::Status::OK;
    }

    grpc::Status SubscribeMissionChanged(
        grpc::ServerContext* /* context */,
        const mavsdk::rpc::mission_raw::SubscribeMissionChangedRequest* /* request */,
        grpc::ServerWriter<rpc::mission_raw::MissionChangedResponse>* writer) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            return grpc::Status::OK;
        }

        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);
        auto subscribe_mutex = std::make_shared<std::mutex>();

        const mavsdk::MissionRaw::MissionChangedHandle handle =
            _lazy_plugin.maybe_plugin()->subscribe_mission_changed(
                [this, &writer, &stream_closed_promise, is_finished, subscribe_mutex, &handle](
                    const bool mission_changed) {
                    rpc::mission_raw::MissionChangedResponse rpc_response;

                    rpc_response.set_mission_changed(mission_changed);

                    std::unique_lock<std::mutex> lock(*subscribe_mutex);
                    if (!*is_finished && !writer->Write(rpc_response)) {
                        _lazy_plugin.maybe_plugin()->unsubscribe_mission_changed(handle);

                        *is_finished = true;
                        unregister_stream_stop_promise(stream_closed_promise);
                        stream_closed_promise->set_value();
                    }
                });

        stream_closed_future.wait();
        std::unique_lock<std::mutex> lock(*subscribe_mutex);
        *is_finished = true;

        return grpc::Status::OK;
    }

    grpc::Status ImportQgroundcontrolMission(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::ImportQgroundcontrolMissionRequest* request,
        rpc::mission_raw::ImportQgroundcontrolMissionResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "ImportQgroundcontrolMission sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result =
            _lazy_plugin.maybe_plugin()->import_qgroundcontrol_mission(request->qgc_plan_path());

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);

            response->set_allocated_mission_import_data(
                translateToRpcMissionImportData(result.second).release());
        }

        return grpc::Status::OK;
    }

    grpc::Status ImportQgroundcontrolMissionFromString(
        grpc::ServerContext* /* context */,
        const rpc::mission_raw::ImportQgroundcontrolMissionFromStringRequest* request,
        rpc::mission_raw::ImportQgroundcontrolMissionFromStringResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::MissionRaw::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn()
                << "ImportQgroundcontrolMissionFromString sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->import_qgroundcontrol_mission_from_string(
            request->qgc_plan());

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);

            response->set_allocated_mission_import_data(
                translateToRpcMissionImportData(result.second).release());
        }

        return grpc::Status::OK;
    }

    void stop()
    {
        _stopped.store(true);
        std::lock_guard<std::mutex> lock(_stream_stop_mutex);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom)
    {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            std::lock_guard<std::mutex> lock(_stream_stop_mutex);
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom)
    {
        std::lock_guard<std::mutex> lock(_stream_stop_mutex);
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end();
             /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    LazyPlugin& _lazy_plugin;

    std::atomic<bool> _stopped{false};
    std::mutex _stream_stop_mutex{};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises{};
};

} // namespace mavsdk_server
} // namespace mavsdk