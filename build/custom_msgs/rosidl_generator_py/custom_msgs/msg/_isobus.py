# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msgs:msg/Isobus.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'data'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Isobus(type):
    """Metaclass of message 'Isobus'."""

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
                'custom_msgs.msg.Isobus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__isobus
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__isobus
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__isobus
            cls._TYPE_SUPPORT = module.type_support_msg__msg__isobus
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__isobus

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Isobus(metaclass=Metaclass_Isobus):
    """Message class 'Isobus'."""

    __slots__ = [
        '_header',
        '_priority',
        '_page',
        '_pgn',
        '_sa',
        '_pf',
        '_ps',
        '_data',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'priority': 'uint8',
        'page': 'boolean',
        'pgn': 'uint16',
        'sa': 'uint8',
        'pf': 'uint8',
        'ps': 'uint8',
        'data': 'uint8[8]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 8),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.priority = kwargs.get('priority', int())
        self.page = kwargs.get('page', bool())
        self.pgn = kwargs.get('pgn', int())
        self.sa = kwargs.get('sa', int())
        self.pf = kwargs.get('pf', int())
        self.ps = kwargs.get('ps', int())
        if 'data' not in kwargs:
            self.data = numpy.zeros(8, dtype=numpy.uint8)
        else:
            self.data = numpy.array(kwargs.get('data'), dtype=numpy.uint8)
            assert self.data.shape == (8, )

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
        if self.header != other.header:
            return False
        if self.priority != other.priority:
            return False
        if self.page != other.page:
            return False
        if self.pgn != other.pgn:
            return False
        if self.sa != other.sa:
            return False
        if self.pf != other.pf:
            return False
        if self.ps != other.ps:
            return False
        if all(self.data != other.data):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def priority(self):
        """Message field 'priority'."""
        return self._priority

    @priority.setter
    def priority(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'priority' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'priority' field must be an unsigned integer in [0, 255]"
        self._priority = value

    @property
    def page(self):
        """Message field 'page'."""
        return self._page

    @page.setter
    def page(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'page' field must be of type 'bool'"
        self._page = value

    @property
    def pgn(self):
        """Message field 'pgn'."""
        return self._pgn

    @pgn.setter
    def pgn(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pgn' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'pgn' field must be an unsigned integer in [0, 65535]"
        self._pgn = value

    @property
    def sa(self):
        """Message field 'sa'."""
        return self._sa

    @sa.setter
    def sa(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sa' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sa' field must be an unsigned integer in [0, 255]"
        self._sa = value

    @property
    def pf(self):
        """Message field 'pf'."""
        return self._pf

    @pf.setter
    def pf(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pf' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'pf' field must be an unsigned integer in [0, 255]"
        self._pf = value

    @property
    def ps(self):
        """Message field 'ps'."""
        return self._ps

    @ps.setter
    def ps(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ps' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'ps' field must be an unsigned integer in [0, 255]"
        self._ps = value

    @property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'data' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 8, \
                "The 'data' numpy.ndarray() must have a size of 8"
            self._data = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 8 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'data' field must be a set or sequence with length 8 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._data = numpy.array(value, dtype=numpy.uint8)
