from process_payment import process_payment
from process_payment import InvalidPaymentDetails, PaymentGatewayError
import pytest




def test_should_not_accept_non_existent_user() -> None:
  user_id: str = None

  with pytest.raises(InvalidPaymentDetails):
    process_payment(user_id, 1)


def test_should_accept_existent_user() -> None:
  user_id: int = 123

  assert process_payment(user_id, 1)


def test_should_not_accept_amount_less_than_0() -> None:
  amount: int = -1

  with pytest.raises(InvalidPaymentDetails):
    process_payment(123, amount)


def test_should_not_accept_amount_equal_0() -> None:
  amount: int = 0

  with pytest.raises(InvalidPaymentDetails):
    process_payment(123, amount)


def test_should_accept_ammount_greater_than_0() -> None:
  amount: int = 1

  assert process_payment(123, amount)


def test_should_not_accept_unsupported_currency() -> None:
  currency: str = "aaa"

  with pytest.raises(InvalidPaymentDetails):
    process_payment(123, 1, currency)


def test_should_accept_supported_currency() -> None:
  currency: str = "USD"

  assert process_payment(123, 1, currency)


def test_should_not_accept_attempt_less_than_retries() -> None:
  pass