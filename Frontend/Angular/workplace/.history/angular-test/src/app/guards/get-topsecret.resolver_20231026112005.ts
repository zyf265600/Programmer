import { Injectable } from '@angular/core';
import { Router, Resolve} from '@angular/router';
import { Observable, of } from 'rxjs';

export const getTopsecretResolver: ResolveFn<boolean> = (route, state) => {
  return true;
};
