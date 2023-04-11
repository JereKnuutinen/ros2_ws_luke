# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msgs:msg/Sync.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Sync(type):
    """Metaclass of message 'Sync'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msgs.msg.Sync')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sync
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sync
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sync
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sync
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sync

            from geometry_msgs.msg import PoseStamped
            if PoseStamped.__class__._TYPE_SUPPORT is None:
                PoseStamped.__class__.__import_type_support__()

            from nav_msgs.msg import Odometry
            if Odometry.__class__._TYPE_SUPPORT is None:
                Odometry.__class__.__import_type_support__()

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

            from sensor_msgs.msg import PointCloud2
            if PointCloud2.__class__._TYPE_SUPPORT is None:
                PointCloud2.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Sync(metaclass=Metaclass_Sync):
    """Message class 'Sync'."""

    __slots__ = [
        '_synced_img',
        '_synced_pc_lidar',
        '_synced_odom_cam',
        '_synced_cam_pose',
    ]

    _fields_and_field_types = {
        'synced_img': 'sensor_msgs/Image',
        'synced_pc_lidar': 'sensor_msgs/PointCloud2',
        'synced_odom_cam': 'nav_msgs/Odometry',
        'synced_cam_pose': 'geometry_msgs/PoseStamped',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'PointCloud2'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['nav_msgs', 'msg'], 'Odometry'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import Image
        self.synced_img = kwargs.get('synced_img', Image())
        from sensor_msgs.msg import PointCloud2
        self.synced_pc_lidar = kwargs.get('synced_pc_lidar', PointCloud2())
        from nav_msgs.msg import Odometry
        self.synced_odom_cam = kwargs.get('synced_odom_cam', Odometry())
        from geometry_msgs.msg import PoseStamped
        self.synced_cam_pose = kwargs.get('synced_cam_pose', PoseStamped())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.synced_img != other.synced_img:
            return False
        if self.synced_pc_lidar != other.synced_pc_lidar:
            return False
        if self.synced_odom_cam != other.synced_odom_cam:
            return False
        if self.synced_cam_pose != other.synced_cam_pose:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def synced_img(self):
        """Message field 'synced_img'."""
        return self._synced_img

    @synced_img.setter
    def synced_img(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'synced_img' field must be a sub message of type 'Image'"
        self._synced_img = value

    @property
    def synced_pc_lidar(self):
        """Message field 'synced_pc_lidar'."""
        return self._synced_pc_lidar

    @synced_pc_lidar.setter
    def synced_pc_lidar(self, value):
        if __debug__:
            from sensor_msgs.msg import PointCloud2
            assert \
                isinstance(value, PointCloud2), \
                "The 'synced_pc_lidar' field must be a sub message of type 'PointCloud2'"
        self._synced_pc_lidar = value

    @property
    def synced_odom_cam(self):
        """Message field 'synced_odom_cam'."""
        return self._synced_odom_cam

    @synced_odom_cam.setter
    def synced_odom_cam(self, value):
        if __debug__:
            from nav_msgs.msg import Odometry
            assert \
                isinstance(value, Odometry), \
                "The 'synced_odom_cam' field must be a sub message of type 'Odometry'"
        self._synced_odom_cam = value

    @property
    def synced_cam_pose(self):
        """Message field 'synced_cam_pose'."""
        return self._synced_cam_pose

    @synced_cam_pose.setter
    def synced_cam_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'synced_cam_pose' field must be a sub message of type 'PoseStamped'"
        self._synced_cam_pose = value
