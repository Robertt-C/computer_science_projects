import pytest
from email_validator import validate

def test_should_not_accept_null_strings():
    email = None
    assert not validate(email)

def test_should_not_accept_empty_strings():
    email = ''
    assert not validate(email)

def test_should_accept_valid_email():
    email = 'any@mail.com'
    assert validate(email)

def test_should_not_accept_strings_larger_than_320_chars():
    email = 'l' * 64 + '@' + 'd' * 128 + '.' + 'd' * 127
    assert not validate(email)

def test_should_not_accept_domain_part_larger_than_255_chars():
    email = 'local@' + 'd' * 128 + '.' + 'd' * 127
    assert not validate(email)

def test_should_not_accept_local_part_larger_than_64_chars():
    email = 'l' * 65 + '@mail.com'
    assert not validate(email)

def test_should_not_accept_empty_local_part():
    email = '@mail.com'
    assert not validate(email)

def test_should_not_accept_empty_domain():
    email = 'any@'
    assert not validate(email)

def test_should_not_accept_domain_with_part_larger_than_63_chars():
    email = 'any@' + 'd' * 64 + '.com'
    assert not validate(email)

def test_should_not_accept_local_part_with_space():
    email = 'any email@mail.com'
    assert not validate(email)

def test_should_not_accept_local_part_with_two_dots():
    email = 'any..email@mail.com'
    assert not validate(email)

def test_should_not_accept_local_part_with_ending_dot():
    email = 'any.@mail.com'
    assert not validate(email)

def test_should_not_accept_email_without_an_at_sign():
    email = 'anymail.com'
    assert not validate(email)

def test_should_not_accept_non_strings():
    email = 2
    assert not validate(email)

def test_should_not_accept_local_part_with_invalid_char():
    email = 'anyç@mail.com'
    assert not validate(email)

def test_should_not_accept_domain_part_with_invalid_char():
    email = 'any@mailç.com'
    assert not validate(email)

def test_should_not_accept_email_with_more_than_one_at():
    email = 'any@@mail.com'
    assert not validate(email)

def test_should_accept_strings_with_320_chars():
    email = 'l' * 64 + '@' + 'd' * 128 + '.' + 'd' * 126
    assert validate(email)