import { ComponentFixture, TestBed } from '@angular/core/testing';

import { NavigationComponent } from './navigation.component';

describe('NevigationComponent', () => {
  let component: NevigationComponent;
  let fixture: ComponentFixture<NevigationComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [NevigationComponent]
    });
    fixture = TestBed.createComponent(NevigationComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
