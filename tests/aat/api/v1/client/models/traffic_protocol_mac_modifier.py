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


class TrafficProtocolMacModifier(object):
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
        'method': 'str',
        'list': 'list[MacAddress]',
        'sequence': 'TrafficProtocolMacModifierSequence'
    }

    attribute_map = {
        'method': 'method',
        'list': 'list',
        'sequence': 'sequence'
    }

    def __init__(self, method=None, list=None, sequence=None):  # noqa: E501
        """TrafficProtocolMacModifier - a model defined in Swagger"""  # noqa: E501

        self._method = None
        self._list = None
        self._sequence = None
        self.discriminator = None

        self.method = method
        if list is not None:
            self.list = list
        if sequence is not None:
            self.sequence = sequence

    @property
    def method(self):
        """Gets the method of this TrafficProtocolMacModifier.  # noqa: E501

        Modifier method  # noqa: E501

        :return: The method of this TrafficProtocolMacModifier.  # noqa: E501
        :rtype: str
        """
        return self._method

    @method.setter
    def method(self, method):
        """Sets the method of this TrafficProtocolMacModifier.

        Modifier method  # noqa: E501

        :param method: The method of this TrafficProtocolMacModifier.  # noqa: E501
        :type: str
        """
        self._method = method

    @property
    def list(self):
        """Gets the list of this TrafficProtocolMacModifier.  # noqa: E501

        List of MAC addresses  # noqa: E501

        :return: The list of this TrafficProtocolMacModifier.  # noqa: E501
        :rtype: list[MacAddress]
        """
        return self._list

    @list.setter
    def list(self, list):
        """Sets the list of this TrafficProtocolMacModifier.

        List of MAC addresses  # noqa: E501

        :param list: The list of this TrafficProtocolMacModifier.  # noqa: E501
        :type: list[MacAddress]
        """
        self._list = list

    @property
    def sequence(self):
        """Gets the sequence of this TrafficProtocolMacModifier.  # noqa: E501


        :return: The sequence of this TrafficProtocolMacModifier.  # noqa: E501
        :rtype: TrafficProtocolMacModifierSequence
        """
        return self._sequence

    @sequence.setter
    def sequence(self, sequence):
        """Sets the sequence of this TrafficProtocolMacModifier.


        :param sequence: The sequence of this TrafficProtocolMacModifier.  # noqa: E501
        :type: TrafficProtocolMacModifierSequence
        """
        self._sequence = sequence

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
        if issubclass(TrafficProtocolMacModifier, dict):
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
        if not isinstance(other, TrafficProtocolMacModifier):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
