# CpuGeneratorResult

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **str** | Unique generator result identifier | 
**generator_id** | **str** | CPU generator identifier that generated this result | [optional] 
**active** | **bool** | Indicates whether the result is currently being updated | 
**timestamp_first** | **datetime** | The ISO8601-formatted start time of the generator | 
**timestamp_last** | **datetime** | The ISO8601-formatted date of the last result update | 
**stats** | [**CpuGeneratorStats**](CpuGeneratorStats.md) |  | 
**dynamic_results** | [**DynamicResults**](DynamicResults.md) |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


