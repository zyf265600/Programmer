import { Injectable } from '@angular/core';
import { r } from '@angular/router';

export const getTopsecretResolver: ResolveFn<boolean> = (route, state) => {
  return true;
};
