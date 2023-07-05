// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: perception.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_perception_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_perception_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3008000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3008000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "common.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_perception_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_perception_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[4]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_perception_2eproto;
namespace TechnionFormulaAV {
namespace Messages {
class BoundingBox;
class BoundingBoxDefaultTypeInternal;
extern BoundingBoxDefaultTypeInternal _BoundingBox_default_instance_;
class Cone;
class ConeDefaultTypeInternal;
extern ConeDefaultTypeInternal _Cone_default_instance_;
class ConeMap;
class ConeMapDefaultTypeInternal;
extern ConeMapDefaultTypeInternal _ConeMap_default_instance_;
class FramePosition;
class FramePositionDefaultTypeInternal;
extern FramePositionDefaultTypeInternal _FramePosition_default_instance_;
}  // namespace Messages
}  // namespace TechnionFormulaAV
PROTOBUF_NAMESPACE_OPEN
template<> ::TechnionFormulaAV::Messages::BoundingBox* Arena::CreateMaybeMessage<::TechnionFormulaAV::Messages::BoundingBox>(Arena*);
template<> ::TechnionFormulaAV::Messages::Cone* Arena::CreateMaybeMessage<::TechnionFormulaAV::Messages::Cone>(Arena*);
template<> ::TechnionFormulaAV::Messages::ConeMap* Arena::CreateMaybeMessage<::TechnionFormulaAV::Messages::ConeMap>(Arena*);
template<> ::TechnionFormulaAV::Messages::FramePosition* Arena::CreateMaybeMessage<::TechnionFormulaAV::Messages::FramePosition>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace TechnionFormulaAV {
namespace Messages {

enum ConeType : int {
  UnknownType = 0,
  Yellow = 1,
  Blue = 2,
  Orange = 3,
  OrangeBig = 4,
  ConeType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  ConeType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool ConeType_IsValid(int value);
constexpr ConeType ConeType_MIN = UnknownType;
constexpr ConeType ConeType_MAX = OrangeBig;
constexpr int ConeType_ARRAYSIZE = ConeType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ConeType_descriptor();
template<typename T>
inline const std::string& ConeType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ConeType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ConeType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ConeType_descriptor(), enum_t_value);
}
inline bool ConeType_Parse(
    const std::string& name, ConeType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ConeType>(
    ConeType_descriptor(), name, value);
}
// ===================================================================

class FramePosition :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TechnionFormulaAV.Messages.FramePosition) */ {
 public:
  FramePosition();
  virtual ~FramePosition();

  FramePosition(const FramePosition& from);
  FramePosition(FramePosition&& from) noexcept
    : FramePosition() {
    *this = ::std::move(from);
  }

  inline FramePosition& operator=(const FramePosition& from) {
    CopyFrom(from);
    return *this;
  }
  inline FramePosition& operator=(FramePosition&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const FramePosition& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FramePosition* internal_default_instance() {
    return reinterpret_cast<const FramePosition*>(
               &_FramePosition_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(FramePosition* other);
  friend void swap(FramePosition& a, FramePosition& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline FramePosition* New() const final {
    return CreateMaybeMessage<FramePosition>(nullptr);
  }

  FramePosition* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FramePosition>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FramePosition& from);
  void MergeFrom(const FramePosition& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FramePosition* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TechnionFormulaAV.Messages.FramePosition";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_perception_2eproto);
    return ::descriptor_table_perception_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint32 u = 1;
  void clear_u();
  static const int kUFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::uint32 u() const;
  void set_u(::PROTOBUF_NAMESPACE_ID::uint32 value);

  // uint32 v = 2;
  void clear_v();
  static const int kVFieldNumber = 2;
  ::PROTOBUF_NAMESPACE_ID::uint32 v() const;
  void set_v(::PROTOBUF_NAMESPACE_ID::uint32 value);

  // uint64 depth = 3;
  void clear_depth();
  static const int kDepthFieldNumber = 3;
  ::PROTOBUF_NAMESPACE_ID::uint64 depth() const;
  void set_depth(::PROTOBUF_NAMESPACE_ID::uint64 value);

  // @@protoc_insertion_point(class_scope:TechnionFormulaAV.Messages.FramePosition)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::uint32 u_;
  ::PROTOBUF_NAMESPACE_ID::uint32 v_;
  ::PROTOBUF_NAMESPACE_ID::uint64 depth_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_perception_2eproto;
};
// -------------------------------------------------------------------

class Cone :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TechnionFormulaAV.Messages.Cone) */ {
 public:
  Cone();
  virtual ~Cone();

  Cone(const Cone& from);
  Cone(Cone&& from) noexcept
    : Cone() {
    *this = ::std::move(from);
  }

  inline Cone& operator=(const Cone& from) {
    CopyFrom(from);
    return *this;
  }
  inline Cone& operator=(Cone&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Cone& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Cone* internal_default_instance() {
    return reinterpret_cast<const Cone*>(
               &_Cone_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Cone* other);
  friend void swap(Cone& a, Cone& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Cone* New() const final {
    return CreateMaybeMessage<Cone>(nullptr);
  }

  Cone* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Cone>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Cone& from);
  void MergeFrom(const Cone& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Cone* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TechnionFormulaAV.Messages.Cone";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_perception_2eproto);
    return ::descriptor_table_perception_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // double x = 2;
  void clear_x();
  static const int kXFieldNumber = 2;
  double x() const;
  void set_x(double value);

  // double y = 3;
  void clear_y();
  static const int kYFieldNumber = 3;
  double y() const;
  void set_y(double value);

  // uint32 cone_id = 1;
  void clear_cone_id();
  static const int kConeIdFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::uint32 cone_id() const;
  void set_cone_id(::PROTOBUF_NAMESPACE_ID::uint32 value);

  // .TechnionFormulaAV.Messages.ConeType type = 5;
  void clear_type();
  static const int kTypeFieldNumber = 5;
  ::TechnionFormulaAV::Messages::ConeType type() const;
  void set_type(::TechnionFormulaAV::Messages::ConeType value);

  // double z = 4;
  void clear_z();
  static const int kZFieldNumber = 4;
  double z() const;
  void set_z(double value);

  // float confidence = 6;
  void clear_confidence();
  static const int kConfidenceFieldNumber = 6;
  float confidence() const;
  void set_confidence(float value);

  // @@protoc_insertion_point(class_scope:TechnionFormulaAV.Messages.Cone)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  double x_;
  double y_;
  ::PROTOBUF_NAMESPACE_ID::uint32 cone_id_;
  int type_;
  double z_;
  float confidence_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_perception_2eproto;
};
// -------------------------------------------------------------------

class BoundingBox :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TechnionFormulaAV.Messages.BoundingBox) */ {
 public:
  BoundingBox();
  virtual ~BoundingBox();

  BoundingBox(const BoundingBox& from);
  BoundingBox(BoundingBox&& from) noexcept
    : BoundingBox() {
    *this = ::std::move(from);
  }

  inline BoundingBox& operator=(const BoundingBox& from) {
    CopyFrom(from);
    return *this;
  }
  inline BoundingBox& operator=(BoundingBox&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const BoundingBox& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BoundingBox* internal_default_instance() {
    return reinterpret_cast<const BoundingBox*>(
               &_BoundingBox_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(BoundingBox* other);
  friend void swap(BoundingBox& a, BoundingBox& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BoundingBox* New() const final {
    return CreateMaybeMessage<BoundingBox>(nullptr);
  }

  BoundingBox* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<BoundingBox>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const BoundingBox& from);
  void MergeFrom(const BoundingBox& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BoundingBox* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TechnionFormulaAV.Messages.BoundingBox";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_perception_2eproto);
    return ::descriptor_table_perception_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .TechnionFormulaAV.Messages.FramePosition frame_position = 6;
  bool has_frame_position() const;
  void clear_frame_position();
  static const int kFramePositionFieldNumber = 6;
  const ::TechnionFormulaAV::Messages::FramePosition& frame_position() const;
  ::TechnionFormulaAV::Messages::FramePosition* release_frame_position();
  ::TechnionFormulaAV::Messages::FramePosition* mutable_frame_position();
  void set_allocated_frame_position(::TechnionFormulaAV::Messages::FramePosition* frame_position);

  // .TechnionFormulaAV.Messages.Vector3D position = 7;
  bool has_position() const;
  void clear_position();
  static const int kPositionFieldNumber = 7;
  const ::TechnionFormulaAV::Messages::Vector3D& position() const;
  ::TechnionFormulaAV::Messages::Vector3D* release_position();
  ::TechnionFormulaAV::Messages::Vector3D* mutable_position();
  void set_allocated_position(::TechnionFormulaAV::Messages::Vector3D* position);

  // uint32 cone_id = 1;
  void clear_cone_id();
  static const int kConeIdFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::uint32 cone_id() const;
  void set_cone_id(::PROTOBUF_NAMESPACE_ID::uint32 value);

  // .TechnionFormulaAV.Messages.ConeType type = 2;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::TechnionFormulaAV::Messages::ConeType type() const;
  void set_type(::TechnionFormulaAV::Messages::ConeType value);

  // float height = 3;
  void clear_height();
  static const int kHeightFieldNumber = 3;
  float height() const;
  void set_height(float value);

  // float width = 4;
  void clear_width();
  static const int kWidthFieldNumber = 4;
  float width() const;
  void set_width(float value);

  // float length = 5;
  void clear_length();
  static const int kLengthFieldNumber = 5;
  float length() const;
  void set_length(float value);

  // @@protoc_insertion_point(class_scope:TechnionFormulaAV.Messages.BoundingBox)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::TechnionFormulaAV::Messages::FramePosition* frame_position_;
  ::TechnionFormulaAV::Messages::Vector3D* position_;
  ::PROTOBUF_NAMESPACE_ID::uint32 cone_id_;
  int type_;
  float height_;
  float width_;
  float length_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_perception_2eproto;
};
// -------------------------------------------------------------------

class ConeMap :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TechnionFormulaAV.Messages.ConeMap) */ {
 public:
  ConeMap();
  virtual ~ConeMap();

  ConeMap(const ConeMap& from);
  ConeMap(ConeMap&& from) noexcept
    : ConeMap() {
    *this = ::std::move(from);
  }

  inline ConeMap& operator=(const ConeMap& from) {
    CopyFrom(from);
    return *this;
  }
  inline ConeMap& operator=(ConeMap&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ConeMap& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ConeMap* internal_default_instance() {
    return reinterpret_cast<const ConeMap*>(
               &_ConeMap_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(ConeMap* other);
  friend void swap(ConeMap& a, ConeMap& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ConeMap* New() const final {
    return CreateMaybeMessage<ConeMap>(nullptr);
  }

  ConeMap* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ConeMap>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ConeMap& from);
  void MergeFrom(const ConeMap& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ConeMap* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TechnionFormulaAV.Messages.ConeMap";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_perception_2eproto);
    return ::descriptor_table_perception_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .TechnionFormulaAV.Messages.Cone cones = 1;
  int cones_size() const;
  void clear_cones();
  static const int kConesFieldNumber = 1;
  ::TechnionFormulaAV::Messages::Cone* mutable_cones(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TechnionFormulaAV::Messages::Cone >*
      mutable_cones();
  const ::TechnionFormulaAV::Messages::Cone& cones(int index) const;
  ::TechnionFormulaAV::Messages::Cone* add_cones();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TechnionFormulaAV::Messages::Cone >&
      cones() const;

  // @@protoc_insertion_point(class_scope:TechnionFormulaAV.Messages.ConeMap)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TechnionFormulaAV::Messages::Cone > cones_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_perception_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FramePosition

// uint32 u = 1;
inline void FramePosition::clear_u() {
  u_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 FramePosition::u() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.FramePosition.u)
  return u_;
}
inline void FramePosition::set_u(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  u_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.FramePosition.u)
}

// uint32 v = 2;
inline void FramePosition::clear_v() {
  v_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 FramePosition::v() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.FramePosition.v)
  return v_;
}
inline void FramePosition::set_v(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  v_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.FramePosition.v)
}

// uint64 depth = 3;
inline void FramePosition::clear_depth() {
  depth_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 FramePosition::depth() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.FramePosition.depth)
  return depth_;
}
inline void FramePosition::set_depth(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  depth_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.FramePosition.depth)
}

// -------------------------------------------------------------------

// Cone

// uint32 cone_id = 1;
inline void Cone::clear_cone_id() {
  cone_id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Cone::cone_id() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.Cone.cone_id)
  return cone_id_;
}
inline void Cone::set_cone_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  cone_id_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.Cone.cone_id)
}

// double x = 2;
inline void Cone::clear_x() {
  x_ = 0;
}
inline double Cone::x() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.Cone.x)
  return x_;
}
inline void Cone::set_x(double value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.Cone.x)
}

// double y = 3;
inline void Cone::clear_y() {
  y_ = 0;
}
inline double Cone::y() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.Cone.y)
  return y_;
}
inline void Cone::set_y(double value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.Cone.y)
}

// double z = 4;
inline void Cone::clear_z() {
  z_ = 0;
}
inline double Cone::z() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.Cone.z)
  return z_;
}
inline void Cone::set_z(double value) {
  
  z_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.Cone.z)
}

// .TechnionFormulaAV.Messages.ConeType type = 5;
inline void Cone::clear_type() {
  type_ = 0;
}
inline ::TechnionFormulaAV::Messages::ConeType Cone::type() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.Cone.type)
  return static_cast< ::TechnionFormulaAV::Messages::ConeType >(type_);
}
inline void Cone::set_type(::TechnionFormulaAV::Messages::ConeType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.Cone.type)
}

// float confidence = 6;
inline void Cone::clear_confidence() {
  confidence_ = 0;
}
inline float Cone::confidence() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.Cone.confidence)
  return confidence_;
}
inline void Cone::set_confidence(float value) {
  
  confidence_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.Cone.confidence)
}

// -------------------------------------------------------------------

// BoundingBox

// uint32 cone_id = 1;
inline void BoundingBox::clear_cone_id() {
  cone_id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 BoundingBox::cone_id() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.BoundingBox.cone_id)
  return cone_id_;
}
inline void BoundingBox::set_cone_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  cone_id_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.BoundingBox.cone_id)
}

// .TechnionFormulaAV.Messages.ConeType type = 2;
inline void BoundingBox::clear_type() {
  type_ = 0;
}
inline ::TechnionFormulaAV::Messages::ConeType BoundingBox::type() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.BoundingBox.type)
  return static_cast< ::TechnionFormulaAV::Messages::ConeType >(type_);
}
inline void BoundingBox::set_type(::TechnionFormulaAV::Messages::ConeType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.BoundingBox.type)
}

// float height = 3;
inline void BoundingBox::clear_height() {
  height_ = 0;
}
inline float BoundingBox::height() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.BoundingBox.height)
  return height_;
}
inline void BoundingBox::set_height(float value) {
  
  height_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.BoundingBox.height)
}

// float width = 4;
inline void BoundingBox::clear_width() {
  width_ = 0;
}
inline float BoundingBox::width() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.BoundingBox.width)
  return width_;
}
inline void BoundingBox::set_width(float value) {
  
  width_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.BoundingBox.width)
}

// float length = 5;
inline void BoundingBox::clear_length() {
  length_ = 0;
}
inline float BoundingBox::length() const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.BoundingBox.length)
  return length_;
}
inline void BoundingBox::set_length(float value) {
  
  length_ = value;
  // @@protoc_insertion_point(field_set:TechnionFormulaAV.Messages.BoundingBox.length)
}

// .TechnionFormulaAV.Messages.FramePosition frame_position = 6;
inline bool BoundingBox::has_frame_position() const {
  return this != internal_default_instance() && frame_position_ != nullptr;
}
inline void BoundingBox::clear_frame_position() {
  if (GetArenaNoVirtual() == nullptr && frame_position_ != nullptr) {
    delete frame_position_;
  }
  frame_position_ = nullptr;
}
inline const ::TechnionFormulaAV::Messages::FramePosition& BoundingBox::frame_position() const {
  const ::TechnionFormulaAV::Messages::FramePosition* p = frame_position_;
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.BoundingBox.frame_position)
  return p != nullptr ? *p : *reinterpret_cast<const ::TechnionFormulaAV::Messages::FramePosition*>(
      &::TechnionFormulaAV::Messages::_FramePosition_default_instance_);
}
inline ::TechnionFormulaAV::Messages::FramePosition* BoundingBox::release_frame_position() {
  // @@protoc_insertion_point(field_release:TechnionFormulaAV.Messages.BoundingBox.frame_position)
  
  ::TechnionFormulaAV::Messages::FramePosition* temp = frame_position_;
  frame_position_ = nullptr;
  return temp;
}
inline ::TechnionFormulaAV::Messages::FramePosition* BoundingBox::mutable_frame_position() {
  
  if (frame_position_ == nullptr) {
    auto* p = CreateMaybeMessage<::TechnionFormulaAV::Messages::FramePosition>(GetArenaNoVirtual());
    frame_position_ = p;
  }
  // @@protoc_insertion_point(field_mutable:TechnionFormulaAV.Messages.BoundingBox.frame_position)
  return frame_position_;
}
inline void BoundingBox::set_allocated_frame_position(::TechnionFormulaAV::Messages::FramePosition* frame_position) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete frame_position_;
  }
  if (frame_position) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      frame_position = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, frame_position, submessage_arena);
    }
    
  } else {
    
  }
  frame_position_ = frame_position;
  // @@protoc_insertion_point(field_set_allocated:TechnionFormulaAV.Messages.BoundingBox.frame_position)
}

// .TechnionFormulaAV.Messages.Vector3D position = 7;
inline bool BoundingBox::has_position() const {
  return this != internal_default_instance() && position_ != nullptr;
}
inline const ::TechnionFormulaAV::Messages::Vector3D& BoundingBox::position() const {
  const ::TechnionFormulaAV::Messages::Vector3D* p = position_;
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.BoundingBox.position)
  return p != nullptr ? *p : *reinterpret_cast<const ::TechnionFormulaAV::Messages::Vector3D*>(
      &::TechnionFormulaAV::Messages::_Vector3D_default_instance_);
}
inline ::TechnionFormulaAV::Messages::Vector3D* BoundingBox::release_position() {
  // @@protoc_insertion_point(field_release:TechnionFormulaAV.Messages.BoundingBox.position)
  
  ::TechnionFormulaAV::Messages::Vector3D* temp = position_;
  position_ = nullptr;
  return temp;
}
inline ::TechnionFormulaAV::Messages::Vector3D* BoundingBox::mutable_position() {
  
  if (position_ == nullptr) {
    auto* p = CreateMaybeMessage<::TechnionFormulaAV::Messages::Vector3D>(GetArenaNoVirtual());
    position_ = p;
  }
  // @@protoc_insertion_point(field_mutable:TechnionFormulaAV.Messages.BoundingBox.position)
  return position_;
}
inline void BoundingBox::set_allocated_position(::TechnionFormulaAV::Messages::Vector3D* position) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(position_);
  }
  if (position) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      position = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  position_ = position;
  // @@protoc_insertion_point(field_set_allocated:TechnionFormulaAV.Messages.BoundingBox.position)
}

// -------------------------------------------------------------------

// ConeMap

// repeated .TechnionFormulaAV.Messages.Cone cones = 1;
inline int ConeMap::cones_size() const {
  return cones_.size();
}
inline void ConeMap::clear_cones() {
  cones_.Clear();
}
inline ::TechnionFormulaAV::Messages::Cone* ConeMap::mutable_cones(int index) {
  // @@protoc_insertion_point(field_mutable:TechnionFormulaAV.Messages.ConeMap.cones)
  return cones_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TechnionFormulaAV::Messages::Cone >*
ConeMap::mutable_cones() {
  // @@protoc_insertion_point(field_mutable_list:TechnionFormulaAV.Messages.ConeMap.cones)
  return &cones_;
}
inline const ::TechnionFormulaAV::Messages::Cone& ConeMap::cones(int index) const {
  // @@protoc_insertion_point(field_get:TechnionFormulaAV.Messages.ConeMap.cones)
  return cones_.Get(index);
}
inline ::TechnionFormulaAV::Messages::Cone* ConeMap::add_cones() {
  // @@protoc_insertion_point(field_add:TechnionFormulaAV.Messages.ConeMap.cones)
  return cones_.Add();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::TechnionFormulaAV::Messages::Cone >&
ConeMap::cones() const {
  // @@protoc_insertion_point(field_list:TechnionFormulaAV.Messages.ConeMap.cones)
  return cones_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Messages
}  // namespace TechnionFormulaAV

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::TechnionFormulaAV::Messages::ConeType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::TechnionFormulaAV::Messages::ConeType>() {
  return ::TechnionFormulaAV::Messages::ConeType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_perception_2eproto