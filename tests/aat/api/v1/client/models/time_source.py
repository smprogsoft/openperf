# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six


class TimeSource(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'id': 'str',
        'kind': 'str',
        'config': 'TimeSourceConfig',
        'stats': 'TimeSourceStats'
    }

    attribute_map = {
        'id': 'id',
        'kind': 'kind',
        'config': 'config',
        'stats': 'stats'
    }

    def __init__(self, id=None, kind=None, config=None, stats=None):  # noqa: E501
        """TimeSource - a model defined in Swagger"""  # noqa: E501

        self._id = None
        self._kind = None
        self._config = None
        self._stats = None
        self.discriminator = None

        self.id = id
        self.kind = kind
        self.config = config
        self.stats = stats

    @property
    def id(self):
        """Gets the id of this TimeSource.  # noqa: E501

        Unique time source identifier  # noqa: E501

        :return: The id of this TimeSource.  # noqa: E501
        :rtype: str
        """
        return self._id

    @id.setter
    def id(self, id):
        """Sets the id of this TimeSource.

        Unique time source identifier  # noqa: E501

        :param id: The id of this TimeSource.  # noqa: E501
        :type: str
        """
        self._id = id

    @property
    def kind(self):
        """Gets the kind of this TimeSource.  # noqa: E501

        time source kind  # noqa: E501

        :return: The kind of this TimeSource.  # noqa: E501
        :rtype: str
        """
        return self._kind

    @kind.setter
    def kind(self, kind):
        """Sets the kind of this TimeSource.

        time source kind  # noqa: E501

        :param kind: The kind of this TimeSource.  # noqa: E501
        :type: str
        """
        self._kind = kind

    @property
    def config(self):
        """Gets the config of this TimeSource.  # noqa: E501


        :return: The config of this TimeSource.  # noqa: E501
        :rtype: TimeSourceConfig
        """
        return self._config

    @config.setter
    def config(self, config):
        """Sets the config of this TimeSource.


        :param config: The config of this TimeSource.  # noqa: E501
        :type: TimeSourceConfig
        """
        self._config = config

    @property
    def stats(self):
        """Gets the stats of this TimeSource.  # noqa: E501


        :return: The stats of this TimeSource.  # noqa: E501
        :rtype: TimeSourceStats
        """
        return self._stats

    @stats.setter
    def stats(self, stats):
        """Sets the stats of this TimeSource.


        :param stats: The stats of this TimeSource.  # noqa: E501
        :type: TimeSourceStats
        """
        self._stats = stats

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(TimeSource, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, TimeSource):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
